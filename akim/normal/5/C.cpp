#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1000100;

vector<int> vc[2 * maxn];
int idx[2 * maxn];
int st[maxn], pos[maxn], stsz = 0;


int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	string s;
	getline(cin, s);
	int n = s.length();
	int bal = maxn, len = 0, cnt = 1;
	st[stsz] = bal, pos[stsz++] = -1;
	vc[bal].pb(-1);
	for(int i = 0; i < n; i++) {
		bal += s[i] == '(' ? 1 : -1;
		int &j = idx[bal];
		while (j < (int)vc[bal].size()) {
			int ppos = vc[bal][j];
			int mn = lower_bound(&pos[0], &pos[stsz], ppos) - &pos[0];
			if(mn < stsz && st[mn] < bal) {
				j++;
			} else {
				if(i - ppos > len) {
					len = i - ppos;
					cnt = 1;
				} else
				if(i - ppos == len) {
					cnt++;
				}
				break;
			}
		}
		while(stsz > 0 && st[stsz - 1] > bal) {
			stsz--;
		}
		st[stsz] = bal, pos[stsz++] = i;
		vc[bal].pb(i);
	}

	cout << len << " " << cnt;

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim