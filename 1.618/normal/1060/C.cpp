#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 2005
using namespace std;
typedef long long ll;
int n,m;
ll a[maxn],sa[maxn];
ll b[maxn],sb[maxn],x;
ll lena[maxn],lenb[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sa[i] = sa[i - 1] + a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%I64d",&b[i]);
		sb[i] = sb[i - 1] + b[i];
	}
	scanf("%I64d",&x);
	memset(lena,0x3f,sizeof(lena));
	memset(lenb,0x3f,sizeof(lenb));
	for(int i=1;i<=n;i++){
		for(int j=1;j + i - 1 <= n;j++){
			lena[i] = min(lena[i],sa[j + i - 1] - sa[j - 1]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j + i - 1 <= m;j++){
			lenb[i] = min(lenb[i],sb[j + i - 1] - sb[j - 1]);
		}
	}
	ll ans = 0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(lena[i] * lenb[j] <= x) ans = max(ans,i * j);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}