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
#define endl "\n"
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
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 998244353L;

lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n&1)
        return (a*po(a,n-1))%mod;
    lli c=po(a,n/2);
    return (c*c)%mod;
}

    lli T,n,i,j,k,in,cnt,l,r,g;
    lli m;
    string s;
    vi a,fac;
    lli mat[105][105],b[105][105],c[105][105];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void pre(lli n)
{
    lli i;
    for(i=2;i*i<=n;++i)
        if(n%i==0)
        {
            fac.pb(i);
            while(n%i==0)
                n/=i;
        }
    if(n!=1)
        fac.pb(n);
    n=mod-1;
    for(g=2;;++g)
    {
        bool fl=true;
        for(auto x:fac)
        {
            if(po(g,n/x)==1)
            {
                fl=false;
                break;
            }
        }
        
        if(fl)
            break;
    }
    // cerr<<g<<endl;
}

void mul(lli m[105][105],lli a[105][105])
{
    lli i,j,l;
    fo(i,k)
    fo(j,k)
    {
        c[i][j]=0;
        fo(l,k)
        {
            c[i][j]+=(m[i][l]*a[l][j])%(mod-1);
            c[i][j]%=mod-1;
        }
    }
    
    fo(i,k)
    fo(j,k)
        m[i][j]=c[i][j];
    
}

void po(lli n)
{
    assert(n>=0);
    if(n==0)
        return;
    po(n/2);
    mul(mat,mat);
    if(n&1)
        mul(mat,b);
}

lli sol(lli a,lli b)
{
    map<lli,lli> m;
    m.clear();
    lli c=1;
    lli i;
    m.insert({1,0});
    repA(i,1,32000)
    {
        c=(c*a)%mod;
        if(m.find(c)==m.end())
            m.insert({c,i});
        else
            break;
    }
    a=po(a,32000);
    a=po(a,mod-2);
    c=1;
    repA(i,0,32000)
    {
        auto it=m.find((c*b)%mod);
        if(it!=m.end())
            return i*32000+it->Y;
        c=(c*a)%mod;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    // pre(mod-1);
    g=3;
    cin>>k;
    a.clear();a.reserve(k);
    fo(i,k)
    {
        // cin>>in;
        // a.pb(in);
        cin>>b[0][i];
        mat[i][i]=1;
    }
    
    fo(i,k-1)
        b[i+1][i]=1;
    cin>>n>>m;
    
    po(n-k);
    // cout<<mat[0][0]<<endl;
    // return 0;
    lli zz=sol(po(3,mat[0][0]),m);
    cerr<<zz<<endl;
    if(zz==-1)
        cout<<-1<<endl;
    else
        cout<<po(3,zz)<<endl;
}   aryanc403();
    return 0;
}