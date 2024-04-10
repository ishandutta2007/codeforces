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
#define maxn 100100

#define mod 1000000007

typedef long long ll;
using namespace std;

ll exp(ll a,ll b){
	if(b == 0) return 1;
	ll r = exp(a,b/2);
	r = (r*r)%mod;
	if(b%2 == 1)
		r = (r*a)%mod;
	return r;
}

int ans[484][maxn];

map<int,int> mp;

int cur[maxn];

const int N = 100001;

int e25[maxn];
int e26[maxn];
int ei26[maxn];

ll mul3(ll a,ll b,ll c){
	a *= c;
	a %= mod;
	a *= b;
	a %= mod;
	return a;
}

ll fat[maxn];
ll ifat[maxn];

inline ll C(int n,int k){
	if(k < 0 || n < 0 || k > n) return 0;
	ll ret =  mul3(fat[n],ifat[k],ifat[n-k]);
	//debug("C(%d;%d) = %lld\n",n,k,ret);
	return ret;
}

void go(int len){
	
	//debug("go %d\n",len);
	
	ll sum = 0;
	
	for(int i=1;i<=N;i++){
		
		if(i < len){
			cur[i] = 0;
			//debug("%d bad\n",i);
			continue;
		}
		
		//debug("mul %lld %d %d\n",C(i-1,len-1) , e25[i-len] , ei26[i]);
		sum += mul3(C(i-1,len-1) , e25[i-len] , ei26[i]);
		if(sum >= mod) sum -= mod;

		cur[i] = mul3(1,sum,e26[i]);
		//debug("%d %d\n",i,cur[i]);
		
	}
}

char str[maxn];

char ch;
int rt;
int read(){
	rt = 0;
	while((ch=getchar()) >= '0')
		rt = 10*rt + ch-'0';
	return rt;
}

int getlen(){
	rt = 0;
	while((ch=getchar()) >= 'a')
		rt++;
	return rt;
}

main(){
	
	int q=read();
	
	fat[0] = ifat[0] = 1;
	
	for(int i=1;i<maxn;i++){
		fat[i] = ((ll)fat[i-1]*i)%mod;
		ifat[i] = exp(fat[i],mod-2);
	}
	
	int i26 = exp(26,mod-2);
	
	e26[0] = ei26[0] = 1;
	e25[0] = 1;
	
	for(int i=1;i<maxn;i++){
		e26[i] = ((ll)e26[i-1]*26)%mod;
		e25[i] = ((ll)e25[i-1]*25)%mod;
		ei26[i] = ((ll)ei26[i-1]*i26)%mod;
	}
	
	
	//scanf(" %s",str);
	int len = getlen();
	
	go(len);
	
	for(int i=1;i<=N;i++)
		ans[1][i] = cur[i];
		
	mp[len] = 1;

	int cnt = 2;
	
	for(int i=0;i<q;i++){
		
		int t=read();
		
		if(t == 2){
			int a=read();
			printf("%d\n",ans[mp[len]][a]);
		}
		else {
			//scanf(" %s",str);
			len = getlen();
			if(mp[len]) continue;
			go(len);
			for(int j=1;j<=N;j++)
				ans[cnt][j] = cur[j];
			mp[len] = cnt;
			cnt++;
		}
		
	}
	
}