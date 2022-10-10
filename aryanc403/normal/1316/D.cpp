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
#define sz(x) (lli)(x).size()
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
    vector<vii> a;
    vector<string> ans;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void inv()
{
    cout<<"INVALID"<<endl;
    exit(0);
}

bool chk(lli x,lli y)
{
    return 1<=x&&x<=n&&1<=y&&y<=n;
}

const vii dr = {{-1,0},{1,0},{0,1},{0,-1}};
const string drs="DULR";
const string drl="UDRL";

void dfs(lli r,lli c)
{
    lli k;
    fo(k,4)
    {
        if(chk(r+dr[k].X,c+dr[k].Y)&&ans[r+dr[k].X][c+dr[k].Y]=='.'&&a[r][c]==a[r+dr[k].X][c+dr[k].Y])
        {
            ans[r+dr[k].X][c+dr[k].Y]=drs[k];
            dfs(r+dr[k].X,c+dr[k].Y);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    
    a.resize(n+3,vii(n+3));
    ans.resize(n+1);

    repA(i,1,n)
    {
        ans[i]+='.';
        repA(j,1,n)
        {
            cin>>a[i][j].X>>a[i][j].Y;
            ans[i]+=".";
        }
    }

    dbg(ans);

    repA(i,1,n)
    repA(j,1,n)
    {
        if(a[i][j].X==i&&a[i][j].Y==j)
        {
            ans[i][j]='X';
            dfs(i,j);
            continue;
        }
    }

    repA(i,1,n)
    repA(j,1,n)
    {
        if(ans[i][j]!='.')
            continue;
        if(a[i][j].X!=-1||a[i][j].Y!=-1)
        {
            inv();
            continue;
        }

        lli k;
        fo(k,4)
        {
            if(chk(i+dr[k].X,j+dr[k].Y)&&a[i][j]==a[i+dr[k].X][j+dr[k].Y])
            {
                ans[i][j]=drl[k];
                break;
            }
        }
        dbg(i,j,k);
        if(k==4)
            inv();
    }
    

    cout<<"VALID"<<endl;
    repA(i,1,n)
        cout<<ans[i].substr(1)<<endl;

}   aryanc403();
    return 0;
}