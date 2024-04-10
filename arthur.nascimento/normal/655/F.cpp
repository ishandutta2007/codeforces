#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxl 1001000
#define mod 1000000007

typedef long long ll;
using namespace std;

int f[maxl];

int fat[maxl];

ll exp(ll a,ll b){
	if(b == 0)
		return 1;
	ll k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2 == 1)
		k = (k*a) % mod;
	return k;
}


int INV[maxl];


char ch;
int rt ;
inline int get(){
	rt = 0;
	while((ch=getchar()) >= '0')
		rt = 10*rt+ch-'0';
	return rt;
}

ll inv(ll a){
	return exp(a%mod,mod-2);
}

ll C(int n,int k){
	if(n < 0 || k < 0 || k > n)
		return 0;
	ll ret = (ll) fat[n] * INV[k];
	ret %= mod;
	ret *= INV[n-k];
	return ret % mod;
debug("C(%d,%d) = %d\n",n,k,(int)ret);
	return ret;
}

int sieve[maxl];

ll ans = 0;

int P[30];
int T[30];

int arr[maxl];

int k;

void gera(int pos,int qnt,int num){

	if(pos == qnt){
		ans -= ((ll) f[num] * C(arr[num],k)) % mod;
		ans %= mod;
		if(ans < 0) ans += mod;
		arr[num]++;
		ans += ((ll) f[num] * C(arr[num],k)) % mod;
		ans %= mod;
		if(ans < 0) ans += mod;
		return;
	}

	for(int i=0;i<=T[pos];i++){
		gera(pos+1,qnt,num);
		num *= P[pos];
	}

}

void add(int a){

	int qnt = 0;

	while(a != 1){
		int pr = sieve[a];
		P[qnt] = pr;
		T[qnt] = 0;
		while(a%pr == 0){
			a /= pr;
			T[qnt]++;
		}
		qnt++;
	}

	gera(0,qnt,1);

}

main(){

	fat[0] = 1;
	for(int i=1;i<maxl;i++){
		fat[i] = ((ll) i * fat[i-1]) % mod;
		f[i] += i;
		f[i] %= mod;
		for(int j=2*i;j<maxl;j+=i)
			f[j] -= f[i];
	}

	for(int i=0;i<maxl;i++){
		INV[i] = exp(fat[i],mod-2);
	}

	for(int i=1;i<12;i++)
		debug("%d\n",f[i]);

	for(int i=2;i<maxl;i++)
		if(sieve[i] == 0){
			sieve[i] = i;
			for(int j=2*i;j<maxl;j+=i)
				sieve[j] = i;
		}

	int n,q;
	//scanf("%d%d%d",&n,&k,&q);
	n = get();
	k = get();
	q = get();
	

	while(n--){
		int u=  get();
		add(u);
	}

	while(q--){
		int u= get();
		add(u);
		
		printf("%d\n",(int)ans);
	}

}