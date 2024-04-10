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

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    vii a;
    ii x;
    set<ii> s[6];
    set<ii> :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void add(ii a,ii b,set<ii> &s)
// a->b
//a right/lef
{
    lli x=a.X;
    while(x<b.X)
    {
        s.insert({x,a.Y});
        x++;
    }
    while(x>b.X)
    {
        s.insert({x,a.Y});
        x--;
    }
    s.insert({x,a.Y});
    
    lli y=a.Y;
    while(y<b.Y)
    {
        s.insert({b.X,y});
        y++;
    }
    while(y>b.Y)
    {
        s.insert({b.X,y});
        y--;
    }
    s.insert({b.X,y});
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    fo(i,3)
    {
        cin>>x.X>>x.Y;
        a.pb(x);
    }
    
    
    fo(i,3)
    {
        fo(j,3)
        {
            if(i==j)
                continue;
            add(a[i],a[j],s[2*i]);
            add(a[j],a[i],s[2*i+1]);
        }
    }
    
    //erase house coordinates.
    
    // for(auto x:a)
    // {
    //     fo(i,6)
    //     {
    //         it=s[i].find(x);
    //         if(it!=s[i].end())
    //             s[i].erase(it);
    //     }
    // }
    
    repA(i,1,5)
    {
        if((lli)s[i].size()<(lli)s[0].size())
            s[0].swap(s[i]);
    }
    cout<<(lli)s[0].size()<<endl;
    for(auto x:s[0])
        cout<<x.X<<" "<<x.Y<<endl;
    
}   aryanc403();
    return 0;
}