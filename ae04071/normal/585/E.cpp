#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;

const int MAXA=1e7,MOD=1e9+7;
int n,a[500000],sd[MAXA+1],cnt[MAXA+1],pw[500001];
int mu[MAXA+1],ci[500001];
vector<int> primes[500000];

inline int SUB(int a,int b) {return (a-b+MOD)%MOD;}
inline int ADD(int a,int b) {return ((a+b)%MOD+MOD)%MOD;}
void add_cnt(int &i, int idx, int v) {
	if(sz(primes[i]) == idx) cnt[v]++;
	else {
		add_cnt(i, idx+1, v);
		add_cnt(i, idx+1, v*primes[i][idx]);
	}
}
int cal(int &i, int idx, int v) {
	if(sz(primes[i]) == idx) {
		if(v==1) return 0;
		else return mu[v]*SUB(pw[cnt[v]],1);
	} else {
		return ADD(cal(i, idx+1, v), cal(i, idx+1, v*primes[i][idx]));
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);

	memset(mu,-1,sizeof(mu));
	for(int i=2;i<=MAXA;i++) if(!sd[i]){
		sd[i] = i;
		if(i<=4000){
			for(int j=i*i;j<=MAXA;j+=i) sd[j] = i;
			for(int j=i*i;j<=MAXA;j+=i*i) mu[j] = 0;
		}
	}
	for(int i=2;i<=MAXA;i++) if(mu[i]==-1) {
		int v=i,c=0;
		while(v > 1) c++, v/=sd[v];
		mu[i] = c%2==1 ? 1 : -1;
	}
	
	pw[0]=1;
	for(int i=1;i<=500000;i++) pw[i]=pw[i-1]*2%MOD;
	
	for(int i=0;i<n;i++) {
		int v = a[i],c=0;
		while(v>1) {
			int div = sd[v];
			while(v % div == 0) v/=div;
			c++;
		}
		primes[i].resize(c);
		v=a[i];
		
		for(int j=0;j<c;j++) {
			int div=sd[v];
			primes[i][j]=div;
			while(v%div==0) v/=div;
		}
		add_cnt(i,0,1);
	}
	
	int tot=0, ans=0;
	for(int i=2;i<=MAXA;i++) if(mu[i]) {
		if(mu[i]>0) tot = ADD(tot, SUB(pw[cnt[i]],1));
		else tot = SUB(tot, SUB(pw[cnt[i]],1));
	}

	for(int i=0;i<n;i++) {
		ans = ADD(ans, SUB(tot, cal(i,0,1)));
	}
	printf("%d\n",ans);
	

	return 0;
}