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
int a[33][33];
int b[33][33];
int c[33];
bool check2(){
	int x=0;
	while(x < m && c[x] == x + 1) x++;
	if(x == m) return 1;
	int cc = m-1;
	while(cc >= 0 && c[cc] == cc+1) cc--;
	swap(c[cc], c[x]);
	for(int i = 0; i < m; i++)
		if(c[i] != i + 1) return 0;
	return 1;
}
bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			c[j] = b[i][j];
		}
		if(!check2()){
			return 0;
		}
	}
	return 1;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for(int j = 0; j < m; j++){
		for(int k = j + 1;k < m; k++){
			for(int i = 0; i < n; i++){
				for(int t = 0; t < m; t++){
					if(t == j) {
					 	b[i][t] = a[i][k];
					}else if(t == k){
						b[i][t] = a[i][j];
					}
					else {
						b[i][t] = a[i][t];
					}
				}
			}
			if(check()){
				cout << "YES\n";
				return;
			}
        }
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			b[i][j] = a[i][j];
		}
	if(check()){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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