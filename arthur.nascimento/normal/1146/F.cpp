#include <bits/stdc++.h>
#define maxn 400400
#define mod 998244353
#define pb push_back
#define ll long long
#define debug 
using namespace std;

int p[maxn];

ll s1[maxn];
ll c1[maxn];
ll c2[maxn];

ll arr[maxn];
ll *pref;
ll suf[maxn];

ll *pref2;
ll suf2[maxn];

ll arr2[maxn];

vector<int> L[maxn];

void go(int vx){
	
	if(L[vx].size() == 0){
	
		c1[vx] = s1[vx] = 1;
		c2[vx] = 0;
		return;
	}
	
	for(int i=0;i<L[vx].size();i++)
		go(L[vx][i]);
		
	pref[-1] = 1;
	for(int i=0;i<L[vx].size();i++)
		pref[i] = (pref[i-1]*s1[L[vx][i]]) % mod;
		
	pref2[-1] = 1;
	for(int i=0;i<L[vx].size();i++)
		pref2[i] = (pref2[i-1] * (s1[L[vx][i]] + c2[L[vx][i]] ) ) % mod;
		
	suf[L[vx].size()] = 1;
	for(int i=L[vx].size()-1;i>=0;i--)
		suf[i] = (suf[i+1]*s1[L[vx][i]]) % mod;
		
	s1[vx] = 1;
	for(int i=0;i<L[vx].size();i++){
		int to = L[vx][i];
		s1[vx] = (s1[vx] * (s1[to] + c2[to])) % mod;
	}
	
	suf2[L[vx].size()] = 1;
	
	for(int i=L[vx].size()-1;i>=0;i--)
		suf2[i] = (suf2[i+1] * (s1[L[vx][i]] + c2[L[vx][i]]) ) % mod;
	
	c1[vx] = 0;
	for(int i=0;i<L[vx].size();i++){
		int to = L[vx][i];
		ll pi = pref2[i-1] * suf2[i+1];
		pi %= mod;
		pi *= (c1[to] + c2[to]);
		pi %= mod;
		c1[vx] += pi;
		c1[vx] %= mod;
	}
	
	c2[vx] = 1;
	ll tira = 1;
	ll ti2 = 0;
	for(int i=0;i<L[vx].size();i++){
		int to = L[vx][i];
		c2[vx] *= (c1[to] + s1[to] + 2*c2[to]);
		c2[vx] %= mod;
		tira *= (s1[to]+c2[to]);
		tira %= mod;
		
		ll pi = pref2[i-1] * suf2[i+1];
		pi %= mod;
		pi *= (c1[to] + c2[to]);
		pi %= mod; debug("+= %lld * %lld\n",pref2[i-1]*suf2[i+1],c1[to]+c2[to]);
		ti2 += pi;
		
		ti2 %= mod;
	}
	
	debug("vx %d tira %lld ti2 %lld\n",vx,tira,ti2);
	c2[vx] -= (tira+ti2);
	
	c2[vx] %= mod;
	c2[vx] += mod;
	c2[vx] %= mod;
	
	debug("vx %d c2 %lld c1 %lld s1 %lld\n",vx,c2[vx],c1[vx],s1[vx]);
	
}

int main(){

	pref = &arr[1];
	pref2 = &arr2[1];
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<n;i++){
		scanf("%d",p+i);
		p[i]--;
		L[p[i]].pb(i);
	}
	
	go(0);
	
	ll ans = c2[0] + s1[0];
	ans %= mod;
	
	printf("%lld\n",ans);

}