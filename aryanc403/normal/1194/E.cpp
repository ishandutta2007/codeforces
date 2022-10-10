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

bool cmp(const pair<lli,ii> &a,const pair<lli,ii> &b)
{
    return a.X<b.X;
}

bool cmp2(const pair<lli,ii> &a,const pair<lli,ii> &b)
{
    return a.Y.X<b.Y.X;
}

const lli mod = 1000000007L;
const lli N = 5000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi ax,ay;
    vector<pair<ii,ii>> a;
    vector<pair<lli,ii>> hor,ver;
    lli bt[4*N+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void update(lli x,lli v)
{
    while(x<=4*N)
    {
        bt[x]+=v;
        x+=x&(-x);
    }
}

lli query(lli x)
{
    lli ans=0;
    while(x>0)
    {
        ans+=bt[x];
        x-=x&(-x);
    }
    return ans;
}

void rsz(vi &a)
{
    sort(a.begin(),a.end());
    // dbg(a);
    a.resize(unique(a.begin(),a.end())-a.begin());
    // dbg(a);
}

lli fnd(const vi &a,lli x)
{
    return lower_bound(a.begin(),a.end(),x)-a.begin();
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli x1,x2,y1,y2;
    cin>>n;
    a.clear();a.reserve(n);
    ax.pb(-N-1);ax.pb(N+1);
    ay=ax;
    fo(i,n)
    {
        cin>>x1>>y1>>x2>>y2;
        // x1+=N;x2+=N;y1+=N;y2+=N;

        if(x1>x2)
            swap(x1,x2);
        if(y1>y2)
            swap(y1,y2);

        a.pb({{x1,y1},{x2,y2}});
        ax.pb(x1);ax.pb(x2);
        ay.pb(y1);ay.pb(y2);
        // if(x1==x2)//vertical

        // else//horizontal

    }

    rsz(ax);
    rsz(ay);

    for(auto &x:a)
    {
        x.X.X=fnd(ax,x.X.X);
        x.Y.X=fnd(ax,x.Y.X);
        x.X.Y=fnd(ay,x.X.Y);
        x.Y.Y=fnd(ay,x.Y.Y);

        if(x.X.X==x.Y.X)//ver
            ver.pb({x.X.X,{x.X.Y,x.Y.Y}});
        else
        {
            hor.pb({x.X.Y,{x.X.X,x.Y.X}});
        }
    }


    // dbg(a);

    sort(ver.begin(),ver.end(),cmp);
    sort(hor.begin(),hor.end(),cmp2);
    lli ans=0;
    n=(lli)ver.size();

    repA(l,0,n-1)
    {
        memset(bt,0,(4*N+5)*sizeof(lli));
        map<lli,vi> m;
        for(auto x:hor)
        {
            if(x.Y.X>ver[l].X)
                break;
            m[x.Y.Y].pb(x.X);
            update(x.X,1);
        }

        auto it=m.begin();
        repA(r,l+1,n-1)
        {
            while(it!=m.end()&&it->X<ver[r].X)
            {
                for(auto x:it->Y)
                    update(x,-1);
                ++it;
            }

            lli u=max(ver[l].Y.X,ver[r].Y.X);
            lli v=min(ver[l].Y.Y,ver[r].Y.Y);

            dbg(ver[l],ver[r],u,v);

            if(u>v)
                continue;

            lli cnt=query(v)-query(u-1);
            // dbg(cnt);
            ans+=cnt*(cnt-1)/2;
        }
    }

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}