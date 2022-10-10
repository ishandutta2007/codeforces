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

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y,q,ty;
    lli m;
    string s;
    ii f[32][800005];
    vi cad;
    lli a[200005][6];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void add(ii f[800005],lli id,lli l,lli r,lli i,lli val)
{
    if(l>r||r<i||i<l)
        return;
    if(l==r)
    {
        f[id]={val,val};// max, min.
        return;
    }
    lli m=(l+r)/2;
    add(f,2*id,l,m,i,val);
    add(f,2*id+1,m+1,r,i,val);
    f[id]={max(f[2*id].X,f[2*id+1].X),min(f[2*id].Y,f[2*id+1].Y)};
}

void SET(lli i)
{
    vi a;
    a.clear();
    lli j,cnt,l;
    fo(j,k)
    {
        cin>>in;
        a.pb(in);
    }

    for(auto j:cad)
    {
        cnt=0;
        fo(l,k)
        {
            if(j&(1LL<<l))
                cnt+=a[l];
            else
                cnt-=a[l];
        }
        add(f[j],1,1,n,i,cnt);
    }
}

ii query(ii f[800005],lli id,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||R<l)
        return {-INF,INF};
    if(L<=l&&r<=R)
        return f[id];
    lli m=(l+r)/2;
    ii a,b;
    a=query(f,2*id,l,m,L,R);
    b=query(f,2*id+1,m+1,r,L,R);
    return {max(a.X,b.X),min(a.Y,b.Y)};
}

lli solve(lli l,lli r)
{
    lli j,ans=0;
    ii a;
    for(auto j:cad)
    {
        a=query(f[j],1,1,n,l,r);
        // dbg(j,a);
        ans=max(ans,a.X-a.Y);
    }
    return ans;
}

void build(lli id,lli l,lli r)
{
    if(l==r)
    {
        lli i;
        for(auto j:cad)
        {
            cnt=0;
            fo(i,k)
            {
                if(j&(1LL<<i))
                    cnt+=a[l][i];
                else
                    cnt-=a[l][i];
            }
            f[j][id]={cnt,cnt};
        }
        return;
    }

    lli m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    for(auto j:cad)
        f[j][id]={max(f[j][2*id].X,f[j][2*id+1].X),min(f[j][2*id].Y,f[j][2*id+1].Y)};
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>k;

    for(i=0;i<(1LL<<k);++i)
    {
        bool fl=false;
        for(auto x:cad)
        {
            if(((1LL<<k)-1)==(i^x))
                fl=true;
        }
        if(fl)
            continue;
        cad.pb(i);
    }

    repA(i,1,n) fo(j,k)     cin>>a[i][j];

    build(1,1,n);

    cin>>q;
    while(q--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>i;
            SET(i);
        }
        else
        {
            cin>>l>>r;
            cout<<solve(l,r)<<endl;
        }
    }

}   aryanc403();
    return 0;
}