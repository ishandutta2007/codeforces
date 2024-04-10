#include<bits/stdc++.h>
#define ll long long
#define N
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
int T, n, a[105];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int sum = 0;
		rep(i, 1, n) sum += a[i];
		bool isp = 1;
		for(int i = 2; i * i <= sum; ++i) {
			if(sum % i == 0) isp = 0;
		}
		if(!isp) {
			printf("%d\n", n);
			rep(i, 1, n) printf("%d ", i);
			printf("\n");
		} else {
			int pos = 0;
			rep(i, 1, n) if(a[i] & 1) {
				pos = i;
				sum -= a[i];
				break;
			}
			printf("%d\n", n - 1);
			rep(i, 1, n) if(i != pos) printf("%d ", i);
			printf("\n");
		}
	}
	return 0;
}