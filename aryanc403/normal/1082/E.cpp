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

    lli T,n,i,j,k,in,cnt,l,r,c;
    lli m;
    string s;
    vi a;
    vi itr[500005];
    vi :: iterator it;
    lli dp1[500005],dp2[500005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>c;
    a.clear();a.reserve(n);
    cnt=0;
    fo(i,n)
    {
        dp1[i]=cnt;
        cin>>in;
        a.pb(in);
        itr[in].pb(i);
        cnt+=(in==c);
    }
    cnt=0;
    repD(i,n-1,0)
    {
        dp2[i]=cnt;
        cnt+=(a[i]==c);
    }
    //cerr<<dp2[1]<<"dp2"<<endl;
    lli ans=(lli)itr[c].size();
    repA(k,1,500000)
    {
        if(k==c||itr[k].empty())
            continue;
        i=j=0;
        n=(lli)itr[k].size();
        while(j<n)
        {
            while(i<j&&j-i+1<=dp1[itr[k][j]]-dp1[itr[k][i]])
                i++;
            //cerr<<k<<" k "<<i<<" "<<j<<" "<<dp1[itr[k][i]]+dp2[itr[k][j]]+j-i+1<<endl;
            ans=max(ans,dp1[itr[k][i]]+dp2[itr[k][j]]+j-i+1);
            j++;
        }
    }
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}