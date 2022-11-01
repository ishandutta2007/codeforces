//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (300*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){ll p=1ll;for(ll i=0;i<b;i++)p*=(ll)a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
map <string,vector <string> > mp;
map <string,vector <string> >::iterator it;
ll n,ans=1,now=1;
string a,b,c;

void dfs(string x)
{
	if(mp[x].size()==0 && now>ans)
		ans=now;
	for(int i=0;i<mp[x].size();i++)
	{
		now++;
		dfs(mp[x][i]);
		now--;
	}	
}

int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        for(int j=0;j<c.size();j++)
        {
            if('A'<=c[j] && c[j]<='Z')
                c[j]=tolower(c[j]);
        }
        for(int j=0;j<a.size();j++)
        {
            if('A'<=a[j] && a[j]<='Z')
                a[j]=tolower(a[j]);
        }
        mp[c].push_back(a);
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
    	string func=it->first;
        dfs(func);
    }
    cout<<ans;
    return 0;
}