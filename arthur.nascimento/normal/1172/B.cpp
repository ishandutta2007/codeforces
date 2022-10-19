#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define pb push_back
#define maxn 400400
#define ll long long
ll fat[maxn];
vector<int> L[maxn];
ll ans = 1;

int go(int vx,int p=-1){

	int fi = 0, sz = 0;
	
	for(int i=0;i<L[vx].size();i++)
		if(L[vx][i] != p){
			fi++;
			sz += go(L[vx][i],vx);
		}
		
	if(vx == 0)ans *= (sz+1);
	else ans *= (fi+1);
	ans %= mod;
	
	ans *= fat[fi];
	ans %= mod;
	
	//printf("%d %d\n",vx,sz+1);
	return sz+1;


}

int main(){

	int n;
	scanf("%d",&n);
	
	fat[0] = 1;
	for(int i=1;i<=n;i++)
		fat[i] = (fat[i-1]*i) % mod;
	
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
	}
	
	go(0);
	printf("%lld\n",ans);
	
}