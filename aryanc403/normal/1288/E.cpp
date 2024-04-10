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
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef int lli;
// typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
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
const lli R = 2150L;
bool cmp(const pair<ii,lli> &a,const pair<ii,lli> &b)
{
    if(a.X.X/R!=b.X.X/R)
        return a.X.X/R<b.X.X/R;
    lli v=a.X.X/R;
    if(v&1)
        return a.X.Y>b.X.Y;
    return a.X.Y<b.X.Y;
}

const lli mod = 1000000007L;
const lli maxN = 300000L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    vector<pair<ii,lli>> qur;
    vi ans,ap,arr;
    vi a[maxN+5];
    vi f;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void chg(lli x,lli p)
{
    if(f[x])
        cnt--;
    f[x]+=p;
    if(f[x])
        cnt++;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    ap.resize(n+1,0);
    ans.resize(n+1,0);
    f.resize(n+1,0);
    repA(i,1,m)
    {
        cin>>in;
        a[in].pb(m-i);
        ap[in]=1;
        arr.pb(in);
    }

    reverse(all(arr));
    repA(i,1,n)
    {
        arr.pb(i);
        vi &b=a[i];
        reverse(all(b));
        b.pb(m+i-1);
        dbg(i,b);
        lli pvr=-1;
        for(auto x:b)
        {
            if(pvr+1<=x-1)
                qur.pb({{pvr+1,x-1},i});
            pvr=x;
        }
    }
    dbg(arr);
    sort(all(qur),cmp);
    dbg(qur);
    lli l=0,r=-1;
    //[l,r]
    cnt=0;

    for(auto x:qur)
    {
        while(r<x.X.Y)
        {
            r++;
            chg(arr[r],1);
        }

        while(l>x.X.X)
        {
            l--;
            chg(arr[l],1);
        }

        while(r>x.X.Y)
        {
            chg(arr[r],-1);
            r--;
        }

        while(l<x.X.X)
        {
            chg(arr[l],-1);
            l++;
        }
        dbg(x,l,r,cnt);
        ans[x.Y]=max(ans[x.Y],cnt);
    }

    repA(i,1,n)
    {
        if(!ap[i])
            ap[i]=i;
        cout<<ap[i]<<" "<<ans[i]+1<<endl;
    }

}   aryanc403();
    return 0;
}