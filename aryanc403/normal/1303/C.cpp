/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>s;
    vector<vi> e(26);
    vector<bool> vis(26,false);
    lli pvr='0';
    for(auto x:s)
    {
        if(pvr!='0'&&pvr!=x)
        {
            e[pvr-'a'].pb(x-'a');;
            e[x-'a'].pb(pvr-'a');;
        }
        pvr=x;
    }

    bool fl=true;
    fo(i,26)
    {
        sort(all(e[i]));
        e[i].erase(unique(all(e[i])),e[i].end());
        if(sz(e[i])>2)
        {
            fl=false;
            break;
        }
    }

    s="";
    dbg(e);
    fo(i,26)
    {
        if(vis[i]||sz(e[i])>1)
            continue;
        if(sz(e[i])==0)
        {
            s+=(char)i+'a';
            vis[i]=true;
            continue;
        }

        j=i;
        while(true)
        {
            dbg(j)
            lli cur=j;
            for(auto x:e[j])
            {
                if(vis[x])
                    continue;
                s+=(char)j+'a';
                vis[j]=true;
                j=x;
                break;
            }
            if(cur==j)
            {
                s+=(char)j+'a';
                vis[j]=true;
                break;
            }
        }
        if(!fl)
            break;
    }
    dbg(s)
    if(fl&&sz(s)==26)
    {
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

}   aryanc403();
    return 0;
}