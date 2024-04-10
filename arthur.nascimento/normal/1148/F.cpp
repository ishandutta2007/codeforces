#include <bits/stdc++.h>
using namespace std;

#define maxn 300300
#define ll long long 
#define pb push_back

ll val[maxn];
ll mask[maxn];

vector<int> L[77];
vector<int> hass[77];

int parity[maxn];
int last[maxn];

int main(){

	int n;
	scanf("%d",&n);
	
	ll sum = 0;
	
	for(int i=0;i<n;i++){
		scanf("%lld %lld",val+i,mask+i);
		last[i] = 62;
		for(int j=62;j>=0;j--)
			if(mask[i] & (1ll<<j)){
				last[i] = j;
				hass[j].pb(i);
			}
		 L[last[i]].pb(i);
		 sum += val[i];
	}
	
	if(sum < 0){
		for(int i=0;i<n;i++)
			val[i] = -val[i];
	}
	
	ll ans = 0;
	
	for(int i=62;i>=0;i--){
	
		ll take = 0;
		
		for(int j=0;j<L[i].size();j++){
			if(parity[L[i][j]] == 0) take += val[L[i][j]];
			else take -= val[L[i][j]];
		}
		
		if(take > 0){
			ans |= (1ll << i);
			for(int j=0;j<hass[i].size();j++)
				parity[hass[i][j]] ^= 1;		
		}
	
	}
	
	//for(int i=0;i<n;i++)
	//	if(__builtin_popcountll(mask[i]&ans) % 2 == 1)
		//	printf("flips %d %lld\n",i,val[i]);
			//else printf("oi %d\n",__builtin_popcountll(mask[i]^ans) );
	
	printf("%lld\n",ans);

}