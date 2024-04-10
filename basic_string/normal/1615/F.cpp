#include<bits/stdc++.h>
using namespace std;
const int N=2009,P=1e9+7;
char s[N],t[N];
int n;
bool b;
inline void add(int&x,int y){if((x+=y)>=P)x-=P;}
inline bool chk(char c,int x){return c=='?'||c-'0'==x;}
struct DP{
	int f[N][N*2];
	void wk(){
		int i,j,l,x,y;
		for(i=0;i<=n;++i)memset(f[i],0,sizeof f[i]);
		f[0][N]=1;
		for(i=1;i<=n;++i)for(j=-i;j<=i;++j)if(l=f[i-1][j+N])
		for(x=0;x<2;++x)if(chk(s[i],x^(i&1)^b))
		for(y=0;y<2;++y)if(chk(t[i],y^(i&1)^b))
		add(f[i][j+x-y+N],l);
	}
}A,B;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T;
	for(cin>>T;T--;){
	cin>>n>>s+1>>t+1;
	b=0,A.wk();
	reverse(s+1,s+n+1),reverse(t+1,t+n+1);
	b=!(n&1),B.wk();
	int w=0,i,j;
	for(i=1;i<=n;++i)for(j=-i;j<=i;++j)
	w=(w+A.f[i][j+N]*1ll*abs(j)%P*B.f[n-i][N-j])%P;
	cout<<w<<'\n';
}
	return 0;
}