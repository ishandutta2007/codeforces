#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n,q;
int a[N],t[N],f[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&q);
 	rep(i,1,n) scanf("%d",&a[i]);
 	per(i,1,n) f[a[i]] = i;
 	rep(i,1,q){
 		scanf("%d",&t[i]);
 		printf("%d ",f[t[i]]);
 		rep(j,1,50){
 			if(j == t[i]) continue;
 			if(f[j] < f[t[i]]) f[j]++;
 		}
 		f[t[i]] = 1;
 	}
	return 0;
}