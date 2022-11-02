#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 2e5 + 10;
using namespace std;
string s;
void solve(){
	cin >> s;
	map<char, int> M;
	for(int i = 0; i < s.size(); i++) M[s[i]]++;
	int c1 = min(M['D'], M['U']);
	int c2 = min(M['L'], M['R']);
	if(c1 == 0 && c2 == 0) {
		cout << 0 << "\n";
		return;
	}
	if(c1 == 0) {
		cout << 2 << "\n";
		cout << "LR\n";
		return;
	}
	if(c2 == 0) {
		cout << 2 << "\n";
		cout << "UD\n";
		return;
	}
	cout << (c1+c2) * 2 << "\n";
	for(int i = 0; i < c1; i++) cout << "D";
	for(int i = 0; i < c2; i++) cout << "L";
	for(int i = 0; i < c1; i++) cout << "U";
	for(int i = 0; i < c2; i++) cout << "R";
	cout << "\n";
}
int main () {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}