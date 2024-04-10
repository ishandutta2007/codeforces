//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}
 
ll arr[4005][4005],dp[805][4005];
const ll INF=2e9;
 
void cal(int tl,int tr,int l,int r,int k)
{
	if(l==r)
	{
		for(int i=tl;i<=min(tr,l);++i)
			dp[k][l]=min(dp[k][l],dp[k-1][i-1]+arr[l][l]-arr[l][i-1]-arr[i-1][l]+arr[i-1][i-1]);
		return;
	}
	int m=l+r>>1,t=tl;
	for(int i=tl;i<=min(tr,m);++i)
		if(dp[k][m]>dp[k-1][i-1]+arr[m][m]-arr[m][i-1]-arr[i-1][m]+arr[i-1][i-1])
			dp[k][m]=dp[k-1][i-1]+arr[m][m]-arr[m][i-1]-arr[i-1][m]+arr[i-1][i-1],t=i;
	if(l<=m-1) cal(tl,t,l,m-1,k);
	if(m+1<=r) cal(t,tr,m+1,r,k);
}
 
template<typename T>
void get_int(T &tmp)
{
	char c;
	while((c=getchar())<'0');
	tmp=c^'0';
	while((c=getchar())>='0') tmp*=10,tmp+=c^'0';
}
 
int main()
{
	int n,k;
	get_int(n),get_int(k);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			get_int(arr[i][j]),arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
	for(int i=0;i<=n;++i)
		for(int j=0;j<=k;++j)
			dp[j][i]=INF;
	dp[0][0]=0;
	for(int i=1;i<=k;++i)
		cal(i,n,i,n,i);
	cout << dp[k][n]/2 << "\n";
}