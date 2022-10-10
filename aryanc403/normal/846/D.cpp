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
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,q;
    lli a[505][505];
    lli seg[505][4005];
    lli m;
    string s;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

lli query(lli a[4005],lli root,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||R<l)
        return -INF;
    if(L<=l&&r<=R)
        return a[root];
    lli mid=(l+r)/2;
    return max(query(a,2*root,l,mid,L,R),query(a,2*root+1,mid+1,r,L,R));
}

lli query(lli a[4005],lli l,lli r)
{
    return query(a,1,1,m,l,r);
}

lli queryMax(lli x,lli y,lli k)
{
    lli ans=0,i;
    repA(i,x,x+k-1)
        ans=max(ans,query(seg[i],y,y+k-1));
    return ans;
}

void update(lli a[4005],lli root,lli l,lli r,lli pos,lli val)
{
    if(l>r||r<pos||pos<l)
        return;
    a[root]=max(a[root],val);
    if(l==r)
        return;
    lli mid=(l+r)/2;
    update(a,2*root,l,mid,pos,val);
    update(a,2*root+1,mid+1,r,pos,val);
}

void update(lli a[4005],lli pos,lli val)
{
    update(a,1,1,m,pos,val);
}

void update(lli x,lli y,lli val)
{
    update(seg[x],y,val);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m>>k>>q;
    repA(i,1,n)
    repA(j,1,m)
        a[i][j]=INF;
    
    while(q--)
    {
        cin>>i>>j;
        cin>>a[i][j];
    }
    
    repA(i,1,n)
    repA(j,1,m)
    {
        update(i,j,a[i][j]);
    }

    lli ans=INF;
    repA(i,1,n-k+1)
    repA(j,1,m-k+1)
    {
        ans=min(ans,queryMax(i,j,k));
    }
    if(ans==INF)
        ans=-1;
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}