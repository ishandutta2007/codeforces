// Basically SQRT Decomposition.
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
const lli mod = 998244353L;

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
    else
    {
        jt->Y+=cnt;
        if(jt->Y>=mod)
            jt->Y-=mod;
    }
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
const lli blk = 330L;
const lli maxN = 100000L;
const lli blkS = maxN/blk+1;

    lli T,n,i,j,k,in,cnt,l,r;
    lli dp[100005],pvr[100005],b[100005],bSum[blkS+2];
    lli val[blkS][2*blk+1];
    map<lli,lli> m;
    vi a;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

// K = blk = block size.

void update(lli x)
// update on xth block.
// O(K)
{
    lli i,cnt=0;
    bSum[x]=0;
    fo(i,2*blk+1)
        val[x][i]=0;
    i=min(blk*(x+1)-1,n);
    while(i>0&&i/blk==x)
    {
        cnt+=b[i];
        //cerr<<cnt<<" ";
        // add(q[x],cnt,dp[i-1]);
        val[x][cnt+blk]+=dp[i-1];
        if(val[x][cnt+blk]>=mod)
            val[x][cnt+blk]-=mod;
        
        i--;
    }
    
    bSum[x]=cnt;
    cnt=0;
    //cerr<<"Update "<<x<<endl;
    fo(i,2*blk+1)
    {
        cnt+=val[x][i];
        if(cnt>=mod)
            cnt-=mod;
        val[x][i]=cnt;
        //cerr<<cnt<<" ";
    }
    //cerr<<endl<<endl;
}

void add(lli idx)
//O(3*K)
// Updating blocks.
{
    b[idx]=1;
    update(idx/blk);
    if(m.find(a[idx])!=m.end())
    {
        pvr[idx]=m[a[idx]];
        b[pvr[idx]]=-1;
        update(pvr[idx]/blk);
        
        if(pvr[pvr[idx]])
        {
            b[pvr[pvr[idx]]]=0;
            update(pvr[pvr[idx]]/blk);
        }
    }
    m[a[idx]]=idx;
}

lli soln(lli i)
// O(N/K)
// Iterating on blocks.
{
    lli cnt=0,cur=0;
    while(i>=0)
    {
        lli t=k-cur;
        if(-blk<=t&&t<=blk)
            cnt+=val[i][t+blk];
        else if(t>blk)
            cnt+=val[i][2*blk];
        
        if(cnt>=mod)    cnt-=mod;
        cur+=bSum[i];
        i--;
    }
    
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>k;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    dp[0]=1;
    repA(i,1,n)
    {
        add(i);
        dp[i]=soln(i/blk);
        //cout<<i<<" : "<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;

    aryanc403();
    return 0;
}