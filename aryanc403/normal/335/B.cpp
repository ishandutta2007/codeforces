/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

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
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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
const lli C = 26;
const lli N = C*100L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    lli cntc[C+5];
    lli dp[N+5][N+5];
    vi mst[C+5];
    bool fl;
    set<ii> ss[105];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli nxt(char c,lli r)
{
    c-='a';
    auto it=upper_bound(mst[c].begin(),mst[c].end(),r);
    --it;
    return *it;
}

lli solve(lli l,lli r)
{
    if(l>r)
        return dp[l][r]=0;
    lli &ans=dp[l][r];
    if(ans!=-1)
        return ans;
    if(l==r)
        return ans=fl;
    if(s[l]==s[r])
        return ans=2+solve(l+1,r-1);

    ans=solve(l+1,r);
    r=nxt(s[l],r);
    ans=max(ans,solve(l,r));
    return ans;
}

string cal(lli val)
{
    string ans="";
    repA(i,0,n-1)
    repA(j,0,n-1)
        if(dp[i][j]!=-1&&dp[i][j]<=100)
            ss[dp[i][j]].insert(mp(i,j));
    dbg(ss[11],0,n);
    lli l=0,r=n-1;
    while(val>1)
    {
        bool fl=false;
        for(auto x:ss[val])
        {
            if(l<=x.X&&x.Y<=r&&s[x.X]==s[x.Y])
            {
                ss[val-2].find(mp(x.X+1,x.Y-1));
                ans+=s[x.X];
                l=x.X+1;x.Y-1;
                val-=2;
                fl=true;
                break;
            }
        }
        dbg(ans,val);
        assert(fl);
    }
    dbg(l,r);
    if(val>0)
        ans+=s[l];
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>s;
    n=(lli)s.size();
    fl=true;

    for(auto x:s)
        cntc[x-'a']++;

    fo(i,C)
    {
        if(cntc[i]>=100)
        {
            char c='a'+i;
            fo(i,100)
                cout<<c;
            cout<<endl;
            return 0;
        }
    }

    memset(dp,-1,sizeof(dp));
    lli ans=0;
    fo(i,n)
        mst[s[i]-'a'].pb(i);
    assert(n<=N);
    ans=solve(0,n-1);
    dbg(ans);

    if(ans>100)
    {
        fl=false;
        memset(dp,-1,sizeof(dp));
        ans=solve(0,n-1);
        ans=100;
    }

    string s=cal(ans);
    cout<<s;
    if(ans%2)
        s.pop_back();
    reverse(s.begin(),s.end());
    cout<<s;
    cout<<endl;

}   aryanc403();
    return 0;
}