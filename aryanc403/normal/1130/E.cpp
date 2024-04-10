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
const lli maxK = 1000000L;
const lli maxN = 2000L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    string s;
    vi a;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void prt(lli d,lli sum,lli len)
{
    if(len<0||sum>maxK*len)
        return;
    cout<<2*d+len<<endl;
    lli i;
    fo(i,d)
        cout<<1<<" "<<-2<<" ";
    fo(i,len)
    {
        if(sum>=maxK)
        {
            cout<<maxK<<" ";
            sum-=maxK;
        }
        else
        {
            cout<<sum<<" ";
            sum=0;
        }
    }
    //assert(sum==0);
    exit(0);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>k;
    if(k<=maxK)
    {
        cout<<1<<endl<<-k<<endl;
        return 0;
    }
    
    for(lli d=1;d<=maxN/2;++d)
    {
        if(k%d)
            continue;
        cnt=k/d+maxN;
        if(cnt<0)
            continue;
        if(cnt%2==0)
            prt(d,cnt/2,maxN-2*d);
        cnt=k/d+maxN-1;
        if(cnt<0)
            continue;
        if(cnt%2==0)
            prt(d,cnt/2,maxN-2*d-1);
    }
    cout<<-1<<endl;
}   aryanc403();
    return 0;
}