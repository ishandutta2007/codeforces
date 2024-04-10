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
const lli maxK = 15L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a[maxK+5];
    map<lli,lli> st;
    lli sum[maxK+5];
    bool poss[(1LL<<maxK)+5];
    ii cycle[(1LL<<maxK)+5];
    lli pick[maxK+5],drp[maxK+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli addCycle(lli u,lli x,bool fl=false)
{
    lli msk=0;
    vii c;
    while((msk&(1LL<<u))==0)
    {
        c.pb(mp(x,u));
        msk|=(1LL<<u);
        x+=cnt-sum[u];
        auto it=st.find(x);
        if(it==st.end())
            return 0;
        u=it->Y;
    }

    if(c[0]==mp(x,u))
    {
        //cycle found with msk;
        if(fl)
        {
            dbg(c);
            lli n=(lli)c.size();
            for(lli i=0;i<n;++i)
            {
                pick[c[i].Y]=c[i].X;
                drp[c[i].Y]=c[(i-1+n)%n].Y+1;
            }
        }
        else
        {
            poss[msk]=true;
            cycle[msk]=mp(u,x);
        }
        return msk;
    }
    return 0;
}

void findSoln(lli m)
{
    while(m)
    {
        lli v=addCycle(cycle[m].X,cycle[m].Y,true);
        m^=v;
        assert(v>0);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>k;

    fo(i,k)
    {
        cin>>n;
        while(n--)
        {
            cin>>in;
            a[i].pb(in);
            cnt+=in;
            st[in]=i;
            sum[i]+=in;
        }
    }

    if(cnt%k)
    {
        cout<<"No"<<endl;
        return 0;
    }

    cnt/=k;
    dbg(cnt);

    fo(i,k)
    {
        for(auto x:a[i])
            addCycle(i,x);
    }

    for (int mask = 0; mask < (1LL<<k); mask++)
    {
        if(poss[mask])
            continue;
        for(int i = mask; i > 0; i = (i-1) & mask)
        {
            if(poss[i]&&poss[i^mask])
            {
                poss[mask]=true;
                cycle[mask]=cycle[i];
                break;
            }
        }
    }

    if(!poss[(1LL<<k)-1])
    {
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    findSoln((1LL<<k)-1);
    fo(i,k)
        cout<<pick[i]<<" "<<drp[i]<<endl;
}   aryanc403();
    return 0;
}