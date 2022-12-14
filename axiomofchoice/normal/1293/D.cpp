#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll; const int inf=2e9;
typedef double lf; const lf err=1e-7;
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define Clear(a) {a=decltype(a)();}
#define qwq {cerr<<"qwq"<<endl;}
#define orz(x) {cerr<<#x": "<<x<<endl;}
ll read(){ll n; scanf("%lld",&n); return n;}
const int N=110;
const int mod=1e9+7;
#define int ll
int x0,y0,ax,ay,bx,by,xs,ys,t;
int x[N],y[N];
int xx[N],yy[N];
int f(int n,int t,int xs,int ys){
	//repeat(i,0,n){
		//cout<<xx[i]<<','<<yy[i]<<' '
	repeat(i,0,n){
		t-=(abs(xx[i]-xs)+abs(yy[i]-ys));
		if(t<0)return i;
		xs=xx[i],ys=yy[i];
	}
	return n;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	int n=0;
	while(1){
		if((lf)x[n]*ax+bx>2.1e16)break;
		if((lf)y[n]*ay+by>2.1e16)break;
		x[n+1]=x[n]*ax+bx;
		y[n+1]=y[n]*ay+by;
		n++;
	}
	n++;
	int ans=0;
	repeat(i,0,n){
		int nn;
		nn=0;
		xx[nn]=x[i]; yy[nn++]=y[i];
		repeat_back(j,0,i)
			xx[nn]=x[j],yy[nn++]=y[j];
		repeat(j,i+1,n)
			xx[nn]=x[j],yy[nn++]=y[j];
		ans=max(ans,f(nn,t,xs,ys));
		nn=0;
		xx[nn]=x[i]; yy[nn++]=y[i];
		repeat(j,i+1,n)
			xx[nn]=x[j],yy[nn++]=y[j];
		repeat_back(j,0,i)
			xx[nn]=x[j],yy[nn++]=y[j];
		ans=max(ans,f(nn,t,xs,ys));
	}
	cout<<ans<<endl;
	return 0;
}