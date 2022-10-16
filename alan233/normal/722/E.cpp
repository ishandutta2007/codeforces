#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod= 1e9+7;
const int  N= 1e5+5;
int n,m,k,s,ans;
int f[N][33],jc[N*2],inv[N*2];

int mi(int x,int y)// 
{
	int res=1ll;
	while(y){
		if(y%2==1) res=res*x%mod;
		x=x*x%mod;
		y>>=1ll;
	}
	return res%mod;
}


struct node{
	int x,y;
	inline bool friend operator < (const node &b,const node &c){
		if(b.x==c.x) return b.y<c.y;
		return b.x<c.x;
	}
}a[N];

int C(int x,int y){return jc[x]%mod*inv[x-y]%mod*inv[y]%mod;}
//

int calc(node b,node c) {return C(c.x-b.x+c.y-b.y,c.x-b.x);}
//(b1,b2)(c1,c2)

signed main()
{
	cin>>n>>m>>k>>s;
	inv[0]=jc[0]=1;
	for(int i=1;i<=n+m;i++) jc[i]=jc[i-1]*i%mod;//
	for(int i=1;i<=n+m;i++) inv[i]=mi(jc[i],mod-2)%mod;
	for(int i=1;i<=k;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+k+1);
	if(a[1].x!=1||a[1].y!=1) {a[++k]=(node){1,1};s*=2;}
	if(a[k].x!=n||a[k].y!=m) a[++k]=(node){n,m};//	
	else s=(s+1)/2;
	int gs=log2(s)+1;
	sort(a+1,a+k+1);//
	f[1][0]=1;
	for(int i=2;i<=k;i++){
		f[i][1]=calc(a[1],a[i]);
		for(int j=2;j<=gs;j++)//j
			for(int t=1;t<i;t++){//t
				if(a[t].x<=a[i].x&&a[t].y<=a[i].y)
				{
					f[i][j]+=(f[t][j-1]*calc(a[t],a[i]))%mod;
					f[i][j]=(f[i][j]+mod)%mod;
					f[i][j]-=(f[t][j]*calc(a[t],a[i]))%mod;
					f[i][j]=(f[i][j]+mod)%mod;				
			}
	}
}
	ans=0;
	for(int i=1;i<=gs;i++){
		s-=s/2;ans=(ans+(f[k][i]-f[k][i+1])*s%mod+mod)%mod;}
	ans=(ans*mi(calc(a[1],a[k]),mod-2)+mod)%mod;
	cout<<ans;
	return 0;
}