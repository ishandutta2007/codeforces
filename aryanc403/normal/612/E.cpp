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

bool cmp(const vi &a,const vi &b)
{
    return ((lli)a.size())<((lli)b.size());
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    vi a,inv;
    vector<vi> s;
    vector<vi> pairE;
    lli b[1000005];
    bool vis[1000005];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
//cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    
    repA(i,1,n)
    {
        if(vis[i])
            continue;
        inv.clear();
        lli x=i;
        //cout<<"New Inversion"<<x<<endl;
        while(!vis[x])
        {
            inv.pb(x);
          //  cout<<x<<" ";
            vis[x]=true;
            x=a[x];
        }
        // for(auto x:inv)
            // cout<<x<<" ";
        // cout<<endl;
        if(((lli)inv.size())%2)
            s.pb(inv);
        else
            pairE.pb(inv);
    }
    // cout<<n<<endl;
    // exit(0);
    if(((lli)pairE.size())%2)
    {
        cout<<-1;
        exit(0);
    }
    
    sort(pairE.begin(),pairE.end(),cmp);
    for(j=0;j<(lli)pairE.size();j+=2)
    {
        // cout<<pair2[j][0]<<" "<<pair2[j][1]<<" "<<pair2[j+1][0]<<" "<<pair2[j+1][1]<<endl;
        if(((lli)pairE[j].size())!=((lli)pairE[j+1].size()))
        {
            cout<<-1;
            exit(0);
        }
        inv.clear();
        for(auto x:pairE[j])
            inv.pb(x);
        for(auto x:pairE[j+1])
            inv.pb(x);
        s.pb(inv);
    }
    // cerr<<(lli)s.size()<<endl;
    for(auto &a:s)
    {
        inv.clear();
        a.pb(a[0]);
        lli sz=(lli)a.size();
        i=0;
        j=sz/2;
        while(j<sz)
        {
            if(i<sz/2)
                inv.pb(a[i++]);
            inv.pb(a[j++]);
        }
        // cerr<<"Inversion "<<endl;
        // for(auto x:inv)
        //     cerr<<x<<" ";
        // cerr<<endl;
        i=-1;
        for(auto x:inv)
        {
            if(~i)
                b[i]=x;
            i=x;
        }
    }
    
    repA(i,1,n)
        cout<<b[i]<<" ";
}   aryanc403();
    return 0;
}