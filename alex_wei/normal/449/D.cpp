#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef pair <long long,long long> pll;

#define fi first
#define se second
#define gc getchar()
#define pb emplace_back
#define mem(x,v,n) memset(x,v,sizeof(x[0])*n)
#define cpy(x,y,n) memcpy(x,y,sizeof(x[0])*n)

const ld Pi=acos(-1);
const ll mod=1e9+7;

inline ll read(){
    ll x=0; bool sign=0; char s=gc;
    while(!isdigit(s))sign|=s=='-',s=gc;
    while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
    return sign?-x:x;
}
ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	}
	return s;
}

const int N=1<<20;
ll n,a[N],pw[N];
void FWT(ll *a,ll op){
	for(int d=2,k=1;k<N;k<<=1,d<<=1)
		for(int i=0;i<N;i+=d)
			for(int j=0;j<k;j++)
				a[i|j]=(a[i|j]+op*a[i|j|k])%mod;
}
int main(){
	cin>>n,pw[0]=1;
	for(int i=1;i<=n;i++)a[read()]++,pw[i]=(pw[i-1]<<1)%mod;
	FWT(a,1);
	for(int i=0;i<N;i++)a[i]=pw[a[i]];
	FWT(a,mod-1),cout<<a[0]<<endl;
	return 0;
}