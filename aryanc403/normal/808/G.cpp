/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;


    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s,t;
    vi a;
    vector<vi> e;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool chk(lli i)
{
    for(auto x:t)
    {
        if(s[i]!='?'&&s[i]!=x)
            return false;
        i++;
    }

    return true;
}

vi Z(string S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, (int)z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

vector<bool> vis;
void setVis(const string &s)
{
    auto a=Z(s);
    const lli n=sz(s);
    lli i;
    vis.clear();
    fo(i,n)
        vis.pb(a[i]==n-i);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>s;
    cin>>t;

    n=sz(s);
    fo(i,n)
    {
        if(chk(i))
            a.pb(i);
    }

    n=sz(a);

    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }

    e.resize(n);
    m=sz(t);
    setVis(t);
    fo(i,n)
    {
        repA(j,i+1,n-1)
        {
            if(a[j]>=a[i]+m)
                break;
            if(vis[a[j]-a[i]])
                continue;
            e[i].pb(j);
        }
    }

    dbg(a);
    dbg(e);

    vi dp(n+1,0);
    vi dp1(n+1,0);
    
    // e[0].pb(1);e[0].pb(2);
    // e[1].pb(2);
    // e[2].pb(3);
    // e[3].pb(4);
    repD(i,n-1,0)
    {
        if(e[i].empty())
        {
            dp1[i]=dp[i]=1+dp1[i+1];
            continue;
        }

        lli u=e[i].back();
        dp[i]=dp1[u+1];
        lli k=0;
        const vi &bb=e[i];
        repA(j,i+1,u)
        {
            if(j==bb[k])
            {
                k++;
                continue;
            }
            dp[i]=max(dp[i],dp[j]);
        }
        dp[i]++;
        dp1[i]=max(dp[i],dp1[i+1]);
    }

    cout<<dp1[0]<<endl;

}   aryanc403();
    return 0;
}