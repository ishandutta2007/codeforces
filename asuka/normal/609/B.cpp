#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
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
int n,m,a[500015],cnt[15];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,n) scanf("%d",&a[i]),cnt[a[i]]++;
 	ll res = 0;
 	rep(i,1,n){
 		rep(j,1,m) if(j != a[i]) res += cnt[j];
 		cnt[a[i]]--;
 	}
 	printf("%lld\n",res);
	return 0;
}