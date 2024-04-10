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
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif
 
vector<int> v[26];
map<int,int> mpp;
unsigned char mp[1<<26][3];
int state[1000005],cnt[26];
string input,s,t;
 
void pls(int x)
{
	if(mp[x][1]==255&&mp[x][0]==255) 
		mp[x][1]=0,mp[x][0]=0,++mp[x][2];
	else if(mp[x][0]==255)
		mp[x][0]=0,++mp[x][1];
	else 
		++mp[x][0];
}
 
int main()
{
	IOS()
	int q;
	cin >> s >> q;
	for(int i=0;i<s.size();++i)
		v[s[i]-'a'].pb(i);
	for(int i=0;i<26;++i)
		if(v[i].size())
			mpp[v[i][0]]=i;
	for(int i=0;i<s.size();++i)
	{
		int x=0;
		for(auto p=mpp.begin();p!=mpp.end()&&(!i||p->Y!=s[i-1]-'a');++p)
			x|=1<<p->Y,pls(x);
		int t=mpp.begin()->Y;
		mpp.erase(mpp.begin()),++cnt[t];
		if(cnt[t]<v[t].size())
			mpp[v[t][cnt[t]]]=t;
	}
	while(q--)
	{
		int tmp=0;
		cin >> t;
		for(char c:t)
			tmp|=1<<(c-'a');
		cout << ((mp[tmp][2]<<16)|(mp[tmp][1]<<8)|mp[tmp][0]) << "\n";
	}
}