#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	string s;
	getline(cin, s);
	for (int i = sz(s); i --> 0; ) 
		if (s[i] == ' ' && (!isdigit(s[i - 1]) || !isdigit(s[i + 1]))) 
			s.erase(s.begin() + i);
	REP (i, sz(s)) {
		if (s[i] != ' ') {
			if (i && s[i - 1] == ',') {
				s.insert(s.begin() + i, ' ');
			}
		}
	}
	for (int i = sz(s); i --> 0; ) {
		if (s[i] != ' ') {
			if (i + 3 < sz(s) && s[i + 1] == '.' && s[i + 2] == '.' && s[i + 3] == '.') {
				s.insert(s.begin() + i + 1, ' ');
			}
		}
	}
	cout << s << endl;
	return 0;
}