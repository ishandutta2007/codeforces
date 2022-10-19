#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

#define forn(i,n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define for1(i,n) for (int (i) = 1; (i) <= (int)(n); ++(i))
#define all(v) (v).begin(), (v).end()

const int N = 3*100000 + 5;
int top;
string s[N];
const int E = 26;
int ne[N][E];
int tope;
bool term[N];
int q[N];

int add(string & s) {
	int cr = 0;
	int started = -1;
	int finish = -1;
	bool ok = true;
	for (int i = 0; i < (int)s.size(); ++i) {
		char ch = s[i];
		if (ne[cr][ch]) {
			cr = ne[cr][ch];
		} else {
			cr = -1;
			break;
		}
		if (started == -1 && q[cr] == 1) {
			started = i;
		}
		if (started != -1 && term[cr]) {
			ok = true;
			finish = i;
		}
	}
	int res = (int)s.size();
	if (ok) {
		res = min(res, (started+1)+1+((int)s.size()-1-finish));
	}
	if (cr == -1 || !term[cr]) {
		cr = 0;
		++q[cr];
		for (int i = 0; i < (int)s.size(); ++i) {
			char ch = s[i];
			if (!ne[cr][ch]) {
				ne[cr][ch] = ++tope;
			}
			cr = ne[cr][ch];
			++q[cr];
		}
		term[cr] = true;
	}

	return res;
}
void solve() {
	ios::sync_with_stdio(false);
	string line;
	int res = 0;
	while (getline(cin, line)) {
		bool ok = false;
		for (int i = 0; i < (int)line.size(); ++i) {
			if (line[i] >= 'a' && line[i] <= 'z') {
				if (!ok) {
					++top;
				}
				s[top] += line[i];
				ok = true;
			} else {
				++res;
				ok = false;
			}
		}
		++res;
	}
	for (int i = 1; i <= top; ++i) {
		int ans = add(s[i]);
		res += ans;
		// cout<<s[i]<<" "<<ans<<endl;
	}
	cout<<res<<endl;

	// for1(i, top) {
	// 	cout<<s[i]<<endl;
	// }
	// for(int i = 1; i <= 3*100000; ++i) {
	// 	cout<<'a'<<endl;
	// }
}
int main() {
#ifdef albert96
	freopen("input.txt", "r", stdin);
	// freopen("input.txt", "w", stdout);
#else
	#define task ""
	// freopen(task".in", "r", stdin);
	// freopen(task".out", "w", stdout);
#endif
	solve();
#ifdef albert96
	cerr<<"Execution time = "<<1.0*clock()/CLOCKS_PER_SEC<<"ms\n";
#endif
	return 0;
}