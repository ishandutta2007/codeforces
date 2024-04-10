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
int n;
map<string, vector<string> > m;
void solve(){
	cin>>n;
	string nn;
	int k;
	for(int i = 0; i < n; i++){
		cin>>nn >> k;
		string t;
		for(int i = 0; i < k; i++){
			cin >> t;
			m[nn].pb(t);
		}
	}
	cout << m.size() << endl;
	forit(it, m){
		vector<string> v;
		v = it->s;
		sort(all(v));
		v.resize(unique(all(v)) - v.begin());
		vector<string> u;
		for(int i = 0; i < v.size(); i++){
			int ok = 1;
			for(int j = 0; j < v.size(); j++){
				if(i == j || v[i].size() > v[j].size()) continue;
				int x = v[j].size();
				int l = v[i].size();
				if(v[j].substr(x-l) == v[i]){
					ok = 0;
				}
			}
			if(ok) u.pb(v[i]);
		}
		cout << it->f << " "<< u.size();
		forit(it2, u){
			cout << " " << *it2;
		}
		cout << endl;
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}