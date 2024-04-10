#include<bits/stdc++.h>
#define ll long long
#define N 114514
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int T, n;
char a[N], b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		scanf("%s%s", a + 1, b + 1);
		int ans = 0;
		rep(i, 1, n) {
			if(a[i] != b[i]) {
				ans += 2;
				continue;
			} else {
				if(a[i] == '0') {
					if(i < n && a[i + 1] == '1' && b[i + 1] == '1') {
						ans += 2;
						i++;
					} else {
						ans++;
					}
				} else {
					if(i == n) continue;
					if(i < n && a[i + 1] == '0' && b[i + 1] == '0') {
						ans += 2;
						i++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}