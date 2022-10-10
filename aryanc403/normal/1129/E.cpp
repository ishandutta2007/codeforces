/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)
 
  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
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
// #define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

//const lli [3] ={ 999119999L,1000000007L,1000992299L};
//const lli [3] ={ 97L,101L,103L};
//const lli  = chrono::high_resolution_clock::now().time_since_epoch().count();
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return ! ( a <= b );
    }
};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,cnt));
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.Y<b.Y;
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,N;
    lli m;
    vi s;
    vii odr,ans;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .
lli vals[]={5,4,4,2,1,1,0,1,1,2,1};

lli calc(lli u,vi &s)
{
    cout<<1<<endl<<1<<endl;
    cout<<(lli)s.size()<<endl;
    for(auto x:s)
        cout<<x<<" ";cout<<endl;
    //cout<<"Vertex"<<endl;
    cout<<u<<endl;
    cin>>u;
    // assert(u==vals[N++]);
    return u;
}

void rec(lli u,vi &s,lli cnt)
{
    if(cnt==-1)
        cnt=calc(u,s);
    
    if(cnt==0)
        return;
    if((lli)s.size()==cnt)
    {
        for(auto x:s)
            ans.pb({u,x});
        s.clear();
        return;
    }
    lli n=(lli)s.size(),i=0;
    vi a,b;
    for(auto x:s)
    {
        if(i<n/2)
            a.pb(x);
        else
            b.pb(x);
        i++;
    }
    
    n=calc(u,a);
    if(n)
        rec(u,a,n);
    if(cnt-n)
        rec(u,b,cnt-n);
    s.clear();
    for(auto x:a)
        s.pb(x);
    for(auto x:b)
        s.pb(x);
}

void solve(lli u)
{
    if(!s.empty())
        rec(u,s,-1);
    s.pb(u);
    //cout<<"cmp"<<endl<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    // assert(n==vals[N++]);
    repA(i,1,n)
    {
        cout<<1<<endl<<1<<endl;
        cout<<n-1<<endl;
        repA(j,2,n)
            cout<<j<<" ";cout<<endl;
        cout<<i<<endl;
        cin>>in;
        // assert(in==vals[N++]);
        if(i==1)
            in++;
        odr.pb({i,in});
    }
    sort(odr.begin(),odr.end(),cmp);
    for(auto x:odr)
        solve(x.X);
    // assert(N==11);
    cout<<"ANSWER"<<endl;
    for(auto x:ans)
        cout<<x.X<<" "<<x.Y<<endl;
    
}   aryanc403();
    return 0;
}