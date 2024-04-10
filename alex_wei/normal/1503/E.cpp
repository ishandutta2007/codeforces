//I love cute Kelly qwq

#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

inline int read(){
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=x*10+s-'0',s=getchar();
	return x;
}

const int N=4050;
const int mod=998244353;
ll n,m,ans,C[N][N];
ll p(int a,int b){return C[a+b][a];}
int main(){
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=j==i||j==0?1:(C[i-1][j-1]+C[i-1][j])%mod;
	for(ll i=1,s=0;i<n;i++,s=0){
		for(int j=1;j<m;j++){
			s=(s+p(i,j-1)*p(i-1,m-j))%mod;
			ans=(ans+s*p(n-i,m-j-1)%mod*p(n-i-1,j))%mod;
		}
	} swap(n,m);
	for(ll i=1,s=0;i<n;i++,s=0){
		for(int j=1;j<m;j++){
			ans=(ans+s*p(n-i,m-j-1)%mod*p(n-i-1,j))%mod;
			s=(s+p(i,j-1)*p(i-1,m-j))%mod;
		}
	} cout<<(ans<<1)%mod<<endl;
	return 0;
}

/////