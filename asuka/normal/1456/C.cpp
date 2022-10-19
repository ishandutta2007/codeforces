#include<bits/stdc++.h>
#define int long long
#define N 500015
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
using namespace std;
int n,k,a[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&k);k++;
 	rep(i,1,n) scanf("%lld",&a[i]);
 	sort(a+1,a+n+1);
 	//rep(i,1,n) printf("%d ",a[i]);
 	//puts("");
 	int s = 0,pos = 0,res = 0;
 	per(i,1,n){
 		res += s;
 		s += a[i];
 		if(s < 0){
 			pos = i;
 			break;
 		}
 	}
 //	printf("%d\n",pos);
 	a[pos] = s;
 	rep(i,1,pos) res += ((i-1)/k)*a[i];
 	printf("%lld\n",res);
	return 0;
}