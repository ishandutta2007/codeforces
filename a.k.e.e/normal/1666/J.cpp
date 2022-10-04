// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[205][205],d[205][205];
int opt[205][205],f[205];

void solve(int l,int r,int t){
	f[opt[l][r]]=t;
	if(l>=r) return;
	solve(l,opt[l][r]-1,opt[l][r]);
	solve(opt[l][r]+1,r,opt[l][r]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]+=a[i][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]+=a[i-1][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int l=j,r=j+i-1;
			d[l][r]=1ll<<60;
			for(int k=l;k<=r;k++)
				if(chkmin(d[l][r],d[l][k-1]+d[k+1][r]+a[r][n]-a[l-1][n]-a[r][r]+a[l-1][r]+a[r][l-1]-a[l-1][l-1]))
					opt[l][r]=k;
		}
	}
	solve(1,n,0);
	for(int i=1;i<=n;i++) printf("%d ",f[i]);
	printf("\n");
	return 0;
}