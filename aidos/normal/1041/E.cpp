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
int a[1111];
int b[1111];
int u[1111];
void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> a[i] >> b[i];
		u[a[i]]++;
		if(b[i] != n){
			cout << "NO\n";
			return;
		}
	}
	int ind = n-1;
	vector<pii> ans;
	for(int i = n-1; i >= 1; i--){
		if(u[i]){
			int last = n;
			for(int k = 1;k< u[i]; k++){
				while(ind>0 && u[ind] > 0) ind--;
				if(ind > i){
					cout << "NO\n";
					return;
				}
				ans.pb(mp(ind, last));
				last = ind;
				ind--;
			}
			ans.pb(mp(last, i));
		}
	}
	cout << "YES\n";
	for(pii x : ans){
		cout << x.f << " " << x.s << "\n";
	}
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