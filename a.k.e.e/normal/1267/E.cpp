#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,m;
ll a[105][105];
pll c[105];
vector<ll> ans;

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	for(int i=1;i<n;i++){
		ll s=0;
		for(int j=1;j<=m;j++) s-=a[j][i],s+=a[j][n];
		for(int j=1;j<=m;j++) c[j]=mp(a[j][n]-a[j][i],j);
		sort(c+1,c+m+1);
		if(s<=0) return printf("0\n"),0;
		vector<ll> now(0);
		for(int j=m;j>=1;j--){
			s-=c[j].fi;
			now.push_back(c[j].se);
			if(s<=0) break;
		}
		if(!ans.size()||now.size()<ans.size()) ans=now;
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%lld ",x);
	printf("\n");
	return 0;
}