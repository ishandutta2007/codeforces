#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int n,a[N],f[N*1000];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]); int g = a[1],sum = 0;
 	rep(i,2,n) g = __gcd(g,a[i]);
 	rep(i,1,n) a[i] /= g,sum += a[i];
 	if(sum%2==0){
	 	sum /= 2;
	 	f[0] = 1;
	 	rep(i,1,n) per(j,0,sum){
	 		if(j >= a[i]) f[j] |= f[j-a[i]];
	 	}
	 }else sum /= 2;
 	if(!f[sum]) printf("%d\n",0);
 	else{
 		printf("%d\n",1);
 		rep(i,1,n){
 			if(a[i]&1){
 				printf("%d\n",i);
 				return 0;
 			}
 		}
 	}
	return 0;
}