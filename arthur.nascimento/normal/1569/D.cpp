#include <bits/stdc++.h>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug
#define pii pair<int,int>
using namespace std;

int A[maxn];
int B[maxn];

int cA[maxn];
int cB[maxn];

map<pii,int> mp[2];

void mrk(int x,int y,int n,int *vet,int *res, char dbg,int ii){

	int id = lower_bound(vet,vet+n,x) - vet;
	
	if(id < n && vet[id] == x) return;
	
	debug("%d %c: %d\n",x,dbg,id);
	
	mp[ii][{y,id}]++;
	
	res[id]++;

}


main(){

	int nt;
	scanf("%d",&nt);
	
	while(nt--){
		
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		
		for(int i=0;i<n;i++)
			scanf("%d",A+i);
			
		for(int i=0;i<m;i++)
			scanf("%d",B+i);
			
		while(k--){
			int x,y;
			scanf("%d%d",&x,&y);
			mrk(x,y,n,A,cA,'x',0);
			mrk(y,x,m,B,cB,'y',1);
		}
		
		ll ans = 0;
		
		for(int i=0;i<=n;i++)
			ans += (ll) cA[i] * (cA[i]-1), cA[i] = 0;
			
		for(int i=0;i<=m;i++)
			ans += (ll) cB[i] * (cB[i]-1), cB[i] = 0;
		
		for(int a=0;a<2;a++)	
			for(auto i : mp[a])
				ans -= (ll) i.second * (i.second - 1);
				
		mp[0].clear();
		mp[1].clear();
		
		
			
		printf("%lld\n",ans/2);
	
	}	
	
}