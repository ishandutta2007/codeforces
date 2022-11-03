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
#include <cassert>

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

const int inf = (1ll << 25) - 1;
const int maxn = (int)2e5+100;
const int mod = (int) 1e9 + 7;
using namespace std;
int p[maxn];
int pos[maxn];
int n, m;
int u[maxn];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		--p[i];
		pos[p[i]] = i;
	}
	cin >> m;
	m = n-m;
	int k = 0;
	for(int i = 0; i < n; i++) {
		if(!u[i]) {
			int j = i;
			while(!u[j]) {
				u[j] = 1;
				j = p[j];
			}
			k++;
		}
	}
	std::vector<int> ans;
	if(k < m) {
		for(int i = 0; i < n && k < m; i++) {
			if(p[i] == i) continue;
			for(int j = 0; j < n; j++) {
				u[j] = 0;
			}
			int j = i;
			while(!u[j]) {
				u[j] = 1;
				j = p[j];
			}
			int x = i+1;
			while(!u[x])x++;
			ans.pb(i);
			ans.pb(x);
			++k;
			swap(p[i], p[x]);
			i--;
		}
	}
	if(k > m) {
		for(int i = 0; i < n; i++) {
			u[i] = 0;
		}
		int j = 0;
		while(!u[j]) {
			u[j] = 1;
			j = p[j];
		}
		for(int i = 0; i < n && k > m; i++) {
			if(u[i]) continue;
			ans.pb(0);
			ans.pb(i);
			int j = i;
			while(!u[j]) {
				u[j] = 1;
				j = p[j];
			}
			k--;
			swap(p[0], p[i]);
		}
	} 
	int t = 0;
	for(int i = 0; i < n; i++)
		u[i] = 0;
	for(int i = 0; i < n; i++) {
		if(!u[i]) {
			int j = i;
			while(!u[j]) {
				u[j] = 1;
				j = p[j];
			}
			t++;
		}
	}
	assert(t == m);
	cout << ans.size()/2 << "\n";
	for(int x: ans) cout << x + 1<< " ";
}
int main () {
    int t=1;
   	//scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}