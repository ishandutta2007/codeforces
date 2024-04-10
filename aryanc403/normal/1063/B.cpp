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
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class CMP
{
public:
    bool operator()(pair<ii,ii> a , pair<ii,ii> b) //For min priority_queue .
    {
        return ! ( a.Y.X <= b.Y.X );
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

    lli T,n,i,j,k,in,cnt,l,r,c,x,y;
    lli m;
    string s[2005];
    lli dp[2005][2005];
    vi a;
    vi :: iterator it;
    priority_queue < pair<ii,ii> , vector < pair<ii,ii> > , CMP > pq;// min priority_queue .

void solve()
{
    pq.push({{r,c},{0,0}});
    
    while(!pq.empty())
    {
        auto u=pq.top();pq.pop();
        if(u.X.X<0||u.X.X>=n||u.X.Y<0||u.X.Y>=m||u.Y.X>x||u.Y.Y>y||s[u.X.X][u.X.Y]=='*'||dp[u.X.X][u.X.Y]<=u.Y.X)
            continue;
        // cerr<<u.X.X+1<<" "<<u.X.Y+1<<" "<<u.Y.X<<" "<<u.Y.Y<<endl;
        dp[u.X.X][u.X.Y]=u.Y.X;
        pq.push({{u.X.X+1,u.X.Y},{u.Y.X,u.Y.Y}});
        pq.push({{u.X.X-1,u.X.Y},{u.Y.X,u.Y.Y}});
        pq.push({{u.X.X,u.X.Y-1},{u.Y.X+1,u.Y.Y}});
        pq.push({{u.X.X,u.X.Y+1},{u.Y.X,u.Y.Y+1}});
    }
    
    fo(i,n)
    {
        fo(j,m)
        {
            if(dp[i][j]!=INF)
            {
                cnt++;
                // cerr<<i<<" "<<j<<endl;
                // s[i][j]='#';
            }
        }
        // cerr<<s[i]<<endl;
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    cin>>r>>c;
    cin>>x>>y;
    r--;c--;

    fo(i,n)
    {
        cin>>s[i];
        fo(j,m)
            dp[i][j]=INF;
    }
    
    solve();
    
    cout<<cnt<<endl;
    
}   aryanc403();
    return 0;
}