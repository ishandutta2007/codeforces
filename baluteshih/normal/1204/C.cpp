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

int arr[105][105],p[1000005];
const int INF=1e9;
vector<int> ans;

int main()
{
	IOS()
	int n,m;
	char c;
	cin >> n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin >> c;
			arr[i][j]=c-'0';
			if(arr[i][j]==0&&i!=j)
				arr[i][j]=INF;
		}
	cin >> m;
	for(int i=0;i<m;++i)
		cin >> p[i];
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
	ans.pb(0);
	for(int i=1;i<m;++i)
	{
		while(ans.size()>1&&arr[p[ans[ans.size()-2]]][p[i]]==i-ans[ans.size()-2])
			ans.pop_back();
		ans.pb(i);
	}
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();++i)
		cout << p[ans[i]] << " \n"[i+1==ans.size()];
}