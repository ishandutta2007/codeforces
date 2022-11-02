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
int n, m;
int a[1010][1010];
int b[1010][1010];
int u[1010][1010];
int check(int x){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] >= x) b[i][j] = 1;
			else b[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			u[i][j] = 0;
		}
	}
	vector<int> l;
	for(int i = 0; i < n; i++){
		l.clear();
		for(int j = 0; j < m; j++){
			if(b[i][j]) l.pb(j);
		}
		for(int t = 0; t < l.size(); ++t){
			for(int k = t + 1; k < l.size(); k++){
				if(u[l[t]][l[k]]) return 1;
				u[l[t]][l[k]] = 1;
			}
		}
	}
	return 0;
}
void solve(){
	scanf("%d%d", &n, &m);
	vector<int> V;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
			V.pb(a[i][j]);
		}
	}
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	int res = 0;
	int l = 1, r = V.size()-1;
	while(l<=r){
		int mid = (l + r)>>1;
		if(check(V[mid])){
			l=mid+1;
			res = mid;
		}else{
			r = mid-1;
		}
	}
	printf("%d\n", V[res]);
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