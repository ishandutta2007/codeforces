#include<bits/stdc++.h>
using namespace std;
enum{N=2009,P=998244353};
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
int n,m,s,r,c,k,w[N*2];
basic_string<int>e[N*2];
char a[N][N];
bool v[N*2],b0,b1;
void dfs(int x){
	++n,v[x]=1,s^=w[x];
	for(int i:e[x])if(++m,!v[i])dfs(i);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j;
	cin>>r>>c;
	for(i=1;i<=r;++i)cin>>(a[i]+1);
	if(r%2==0&&c%2==0)b1=1;
	r+=1-r%2,c+=1-c%2;
	for(i=1;i<=r;++i)for(j=1;j<=c;++j)if(isdigit(a[i][j]))w[i]^=a[i][j]-'0',w[j+r]^=a[i][j]-'0';
	else e[i]+=j+r,e[j+r]+=i;
	for(i=1;i<=r+c;++i)if(!v[i]){
		n=m=s=0,dfs(i),m/=2,k+=m-n+1;
		if(n%2==0&&s==1)b0=b1=1;
		else if(n%2==1)s?(b0=1):(b1=1);
	}
	if(i=0,!b0)i=qp(2,k);
	if(!b1)i=(i+qp(2,k))%P;
	cout<<i;
}