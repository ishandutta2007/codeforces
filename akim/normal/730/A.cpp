#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;      

int n;
int a[N];

bool anas[N];

vector<int> ans[N];
int sz;

bool check(int m) {
	set<pair<int, int> > st;
	for(int i = 0; i < n; i++) {
		if(a[i] > m)
			st.insert(mp(a[i], i));
	}

	int fid = 0;
	sz = 0;

	while(!st.empty()) {
		vector<pair<int, int> > l5;
		for(int i = 0; !st.empty() && i < 5; i++) {
			l5.pb(*st.rbegin());
			st.erase(--(st.end()));
		}
		if(l5.size() == 1) {
			while(fid < sz) {
				if(ans[fid].size() > 2) {
					if(ans[fid][0] != l5[0].s) {
						l5.pb(mp(0, ans[fid][0]));
						ans[fid].erase(ans[fid].begin() + 0, ans[fid].begin() + 1);
					} else {
						l5.pb(mp(0, ans[fid][1]));
						ans[fid].erase(ans[fid].begin() + 1, ans[fid].begin() + 2);
					}   						
					break;
				} else {
					fid++;
				}
			}

			if(l5.size() == 1 && m == 0) {
				l5.pb(mp(0, (l5[0].s + 1) % n));
			}

			if(l5.size() == 1) {
				return(0);
			}
		}
		ans[sz].clear();
		for(int i = 0; i < (int)l5.size(); i++) {
			ans[sz].pb(l5[i].s);
			if(l5[i].f - 1 > m) {
				st.insert(mp(l5[i].f - 1, l5[i].s));
			}
		}
		sz++;
	}
	return(1);
}

int main () {
	
	scanf("%d", &n);
	int r = mod;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		r = min(r, a[i] + 1);
	}
	int l = 0;
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		if(check(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	check(l);

	printf("%d\n", l);
	printf("%d\n", sz);
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < (int)ans[i].size(); j++) {
			anas[ans[i][j]] = 1;
		}
		for(int j = 0; j < n; j++) {
			printf("%d", anas[j]);
		}
		printf("\n");
		for(int j = 0; j < (int)ans[i].size(); j++) {
			anas[ans[i][j]] = 0;
		}
	}
	
	

	return 0;
}