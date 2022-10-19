#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define B 3180
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
using namespace std;
int t,n,k,a[N],f[N][25],L[N][25];
int pri[B],cnt,notp[B];
int M[10000015];
void getp(){
	rep(i,2,B){
		if(!notp[i]) pri[++cnt] = i;
		rep(j,1,cnt){
			if(1ll*i*pri[j] >= B) break;
			notp[i*pri[j]] = 1;
			if(!(i%pri[j])) break;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	getp();// printf("%d\n",cnt);
	while(t--){
		scanf("%d%d",&n,&k);
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n) rep(j,1,cnt){
			while((a[i]%(pri[j]*pri[j]))==0){
				a[i] /= (pri[j]*pri[j]);
			}
			if(a[i] < 1ll*pri[j]*pri[j]) break;
		}
		rep(j,0,k){
			int l = 1,cur = 0;
			rep(i,1,n){
				M[a[i]]++;
				if(M[a[i]]>=2) cur++;
				while(cur > j){
					if(M[a[l]] >= 2) cur--;
					M[a[l]]--; l++;
				}
				L[i][j] = l;
			}
			while(l <= n) M[a[l]]--,l++;
		}
		rep(i,1,n) rep(j,0,k) f[i][j] = inf;
		f[0][0] = 0;
		rep(i,1,n){
			rep(j,0,k){
				rep(x,0,j){
					f[i][j] = min(f[i][j],f[L[i][x]-1][j-x]+1);
				}
			}
		}
		printf("%d\n",f[n][k]);
	}
	return 0;
}