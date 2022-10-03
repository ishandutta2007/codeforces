#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MAXN = 500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
int ind[MAXN];
ll BITL[MAXN];
ll BITR[MAXN];

void addl(int id, int val){
	for (int ind=id; ind<MAXN; ind+=ind&(-ind)) BITL[ind]=(BITL[ind]+val)%mod;
}
void addr(int id, int val){
	for (int ind=n-id+1; ind<MAXN; ind+=ind&(-ind)) BITR[ind]=(BITR[ind]+val)%mod;
}
ll getl(int id){
	ll res=0;
	for (int ind=id; ind; ind-=ind&(-ind)) res=(res+BITL[ind])%mod;
	return res;
}
ll getr(int id){
	ll res=0;
	for (int ind=n-id+1; ind; ind-=ind&(-ind)) res=(res+BITR[ind])%mod;
	return res;
}

bool cmp(int i, int j){ return A[i]<A[j];}

int main(){
	scanf("%lld", &n);
	for (int i=1; i<=n; i++){
		scanf("%lld", A+i);
		ind[i]=i;
		ans=(ans+(i*(n-i+1)%mod)*A[i])%mod;
	}
	sort(ind+1, ind+n+1, cmp);
	for (int j=1; j<=n; j++){
		ll i=ind[j];
		ans=(ans+(getl(i)*(n-i+1)%mod)*A[i])%mod;
		ans=(ans+(getr(i)*i%mod)*A[i])%mod;
		addr(i, n-i+1);
		addl(i, i);
	}
	printf("%lld", ans);
	
	return 0;
}