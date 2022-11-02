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
int a[1000100];
int mi[1000100];
int ans[1000100];
int m;

vector<int> A, B;
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0, x; i < m; i++){
		scanf("%d", &x);
		mi[x-1]=1;
	}
	for(int i = 0; i < n; i++){
		if(mi[i]){
			B.pb(i);
			while(B.size()>0&&A.size() > 0){
				int x = A.back();
				A.pop_back();
				if(a[B.back()] == a[x]) {
					B.pop_back();
				}else{
					mi[x] = 1;
					B.pb(x);
				}
			}
			if(B.size()>0){
				printf("NO\n");
				return;
			}
		}
		else A.pb(i);
	}
	while(A.size()>0){
		B.pb(A.back());
		mi[A.back()] = 1;
		A.pop_back();
		while(B.size()>0&&A.size() > 0){
			int x = A.back();
			A.pop_back();
			if(a[B.back()] == a[x]) {
				B.pop_back();
			}else{
				mi[x] = 1;
				B.pb(x);
			}
		}
		if(B.size()>0){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for(int i = 0; i < n; i++){
		if(mi[i]) printf("-");
		printf("%d%c", a[i], " \n"[i + 1 == n]);
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