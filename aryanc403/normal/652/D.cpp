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

bool cmp(const pair<lli,ii> &a,const pair<lli,ii> &b)
{
    return a.Y.X>b.Y.X||(a.Y.X==b.Y.X&&a.Y.Y<b.Y.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    set<lli> s;
    vi a;
    vector< pair<lli,ii> >b;
    vi :: iterator it;
    lli final[1000005],ans[1000005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

lli query(lli root,lli l,lli r,lli R)
{
    if(l>r||a[l]>R)
        return 0;
    if(a[r]<=R)
        return final[root];
    lli m=(l+r)/2;
    return query(2*root,l,m,R)+query(2*root+1,m+1,r,R);
}

lli query(lli r)
{
    return query(1,0,n-1,r);
}

void update(lli root,lli l,lli r,lli R)
{
    if(l>r||a[r]<R||a[l]>R)
        return;
    if(l==r)
    {
        final[root]++;
        return;
    }
    final[root]++;
    lli m=(l+r)/2;
    update(2*root,l,m,R);
    update(2*root+1,m+1,r,R);
}

void update(lli r)
{
    update(1,0,n-1,r);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n);
    b.clear();b.reserve(n);
    
    fo(i,n)
    {
        cin>>l>>r;
        b.pb({i,{l,r}});
        if(s.find(r)==s.end())
        {
            a.pb(r);
            s.insert(r);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),cmp);
    n=(lli)a.size();
    for(auto u:b)
    {
        ans[u.X]=query(u.Y.Y-1);
        update(u.Y.Y);
    }
    
    fo(i,n)
        cout<<ans[i]<<endl;
    
}   aryanc403();
    return 0;
}