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
const int maxn = (int) 1e5 + 10;

using namespace std;

vector<int> g1[4040], g2[4040];

void go(vector<int> t, int lev){
	if(t.size() == 1) return;
	int mid = t.size()/2;
	vector<int> a, b;
	for(int i = 0; i < mid; i++)
		a.pb(t[i]);
	for(int i = mid; i < t.size(); i++)
		b.pb(t[i]);
	for(int i = 0; i < a.size(); i++)
		g1[lev].pb(a[i]);

	for(int i = 0; i < b.size(); i++)
		g2[lev].pb(b[i]);
	go(a, lev+1);
	go(b, lev+1);
}
int ans[2020];
int cur[2020];

int n;
void out(vector<int> x){
	cout << x.size() << endl;
	for(int i = 0; i < x.size(); i++){
		if(i) cout << " ";
		cout<< x[i];
	}
	cout << endl;
	for(int i = 1; i <= n; i++)
		cin>>cur[i];
	for(int i=1; i <= n; i++){
		int k = -1;
		for(int j = 0; j<x.size(); j++)	if(x[j] == i) k=j;
		if(k == -1) ans[i] = min(cur[i], ans[i]);
	}	
}
void solve(){
	cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; i++)
		v.pb(i);
	go(v, 0);
	for(int i = 1; i <= n; i++)
		ans[i] = inf;
	for(int i = 0; i < 10; i++){
		if(g1[i].size()>0){
			out(g1[i]);
		}
		if(g2[i].size()>0){
			out(g2[i]);
		}
	}
	cout << -1<<endl;
	for(int i = 1; i <= n; i++){
		if(i > 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
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