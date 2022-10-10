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

    lli T,n,i,j,k,in,cnt,l,r,t,x,y;
    map<lli,lli> m;
    vii a;
    map<lli,lli> :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>x>>y;
    t=(x+y-1)/y;//<t then don't change.
    a.clear();a.reserve(n);
    fo(i,n)
    {
        cin>>l>>r;
        a.pb({l,r});
    }
    sort(a.begin(),a.end(),cmp);
    
    for(auto z:a)
    {
        bool fl=true;
        while(!m.empty()&&m.begin()->X<=z.X)
        {
            if(z.X+1-t<m.begin()->X)
            {
                fl=false;
                break;
            }
            m.erase(m.begin());
        }
        
        if(fl)
        {
            cnt+=x+y*(z.Y-z.X)%mod;
            // cerr<<"New "<<z.X<<" "<<z.Y<<endl;
        }
        else
        {
            it=m.lower_bound(z.X+2-t);
            lli val=0;
            while(it!=m.end())
            {
                if(it->X>z.X)
                    break;
                val=it->X;
                it++;
            }
            cnt+=y*(z.Y-val+1)%mod;
            // cerr<<"Using "<<m.rbegin()->X-1<<" for "<<z.X<<" "<<z.Y<<endl;
            del(m,val);
        }
        cnt%=mod;
        add(m,z.Y+1);
    }
    //assert(cnt==999999997);
    cout<<cnt<<endl;
}   aryanc403();
    return 0;
}