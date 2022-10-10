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
//#define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
// typedef long double mytype;
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

const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

class mytype{
    public:
    ii x;//Common End Points // x.X=-1 denote invalid.
    ii y,z;//leaf End Points.
        mytype(){x=y=z={0,0};};
        mytype(lli u){x=y={-1,0};z={0,u};};
        mytype(ii u){x=y={-1,0};z=u;};
        mytype(ii a,ii b,ii c){
            x=a;y=b;z=c;
        }
};

bool cmp(const mytype &a,const mytype &b)
{
    if(a.x.X!=b.x.X)
        return a.x.X>b.x.X;
    return a.y.X+a.z.X>b.y.X+b.z.X;
}

bool Cmp(const ii &a,const ii &b)
{
    if(a.X!=b.X)
        return a.X>b.X;
    return a.Y>b.Y;
}

    lli T,n,i,j,k,in,cnt,l,r;
    lli m;
    string s;
    vi a[200005];
    vi :: iterator it;
    mytype dp[200005];
    lli cl=0,tl=0;
    vii soln;
    ii ph[200005];
    vii cld[200005];
    lli fl[200005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

//Pre Process of Farthest vertices from u in subtree of childrens of u.
void dfs0(lli u,lli p)
{
    cld[u].pb({0,u});
    cld[u].pb({0,u});
    for(auto &x:a[u])
    {
        if(x==p)
            continue;
        dfs0(x,u);
        fl[x]=cld[x][0].Y;
        cld[u].pb({cld[x][0].X+1,cld[x][0].Y});
    }
    sort(cld[u].begin(),cld[u].end(),Cmp);
}

//ph[u].Y is Farthest vertex of tree left after removing subtree of u.
void dfs1(lli u,lli p)
{
    for(auto &v:a[u])
    {
        if(v==p)
            continue;
        if(cld[u][0].Y==fl[v])
        //If Farthest vertex in subtree of u is present in subtree of v as well.
        //Choose 2nd Farthest.
        {
            if(ph[u].X+1>cld[u][1].X+1)
                ph[v]={ph[u].X+1,ph[u].Y};
            else
                ph[v]={cld[u][1].X+1,cld[u][1].Y};
        }
        else
        {
            if(ph[u].X+1>cld[u][0].X+1)
                ph[v]={ph[u].X+1,ph[u].Y};
            else
                ph[v]={cld[u][0].X+1,cld[u][0].Y};
        }
        dfs1(v,u);
    }
}

//Main Soln.
void dfs(lli u,lli p)
{
    vector<mytype> b,c;
    for(auto &v:a[u])
    {
        if(v==p)
            continue;
        dfs(v,u);
        b.pb(dp[v]);
        c.pb(dp[v]);
    }
    // cout<<u<<" p"<<p<<endl;
    if((lli)a[u].size()==1)
    {
        // cerr<<u<<"leaf"<<endl;
        dp[u]=mytype(u);
        return;
    }
    
    c.pb(mytype(ph[u]));
    sort(b.begin(),b.end(),cmp);
    sort(c.begin(),c.end(),cmp);
    
    //common Path End Points ?? (in subtree of u) and u.
    //It also includes vertex preprocess in dfs1.
    if(u!=1&&(lli)c.size()>=3&&c[0].x.X!=-1&&c[1].x.X==-1)
    {
        //cerr<<u<<"hello"<<endl;
        b.swap(c);
        if((cl<b[0].x.X+1)||(cl==b[0].x.X+1&&tl<b[0].y.X+b[0].z.X+4+b[1].z.X+b[2].z.X))
        {
            // cerr<<"like one "<<u<<endl;
            cl=b[0].x.X+1;
            tl=b[0].y.X+b[0].z.X+4+b[1].z.X+b[2].z.X;
            soln.clear();
            soln.pb({b[0].y.Y,b[0].z.Y});
            soln.pb({b[1].z.Y,b[2].z.Y});
        }
        b.swap(c);
    }
    
    // if(u==4)
    // {
    //     cerr<<"four b : "<<endl;
    //     for(auto x:b)
    //         cerr<<x.x.X<<" "<<x.x.Y<<" "<<x.y.Y<<" "<<x.z.Y<<endl;
    //     cerr<<endl;
    // }
    
    //No Common path is subtree of u.
    if(b[0].x.X==-1)
    {
        
        // if((lli)b.size()>=4)
        // {
        //     lli i,tll=4;
        //     fo(i,4)
        //         tl+=b[i].z.X;

        //     if(cl==0&&tl<tll)
        //     {
        //         tl=tll;
        //         soln.clear();
        //         soln.pb({b[0].z.Y,b[2].z.Y});
        //         soln.pb({b[3].z.Y,b[1].z.Y});
        //     }
        //     dp[u]=mytype({0,u},{b[0].z.X+1,b[0].z.Y},{b[1].z.X+1,b[1].z.Y});
        //     return;
        // }
        if((lli)b.size()>=2)
        {
            dp[u]=mytype({0,u},{b[0].z.X+1,b[0].z.Y},{b[1].z.X+1,b[1].z.Y});
            return;
        }
        else
        {
            // cerr<<"linear "<<u<<endl;
            dp[u]=b[0];
            dp[u].z.X++;
            return;
        }
    }
    
    dp[u]=b[0];
    dp[u].x.X++;
    dp[u].y.X++;
    dp[u].z.X++;
    
    if((lli)b.size()>=2&&b[0].x.X!=-1&&b[1].x.X!=-1)
{
    if((cl<b[0].x.X+b[1].x.X+2)||(cl==b[0].x.X+b[1].x.X+2&&tl<b[0].y.X+b[0].z.X+4+b[1].y.X+b[1].z.X))
    {
        cl=b[0].x.X+b[1].x.X+2;
        tl=b[0].y.X+b[0].z.X+4+b[1].y.X+b[1].z.X;
        soln.clear();
        soln.pb({b[0].y.Y,b[0].z.Y});
        soln.pb({b[1].y.Y,b[1].z.Y});
    }
}    
    if((lli)b.size()<3)
        return;
    
    if(b[1].x.X==-1)
    {
        // cerr<<"like one here "<<u<<endl;
        if((cl<b[0].x.X+1)||(cl==b[0].x.X+1&&tl<b[0].y.X+b[0].z.X+4+b[1].z.X+b[2].z.X))
        {
            // cerr<<"like one "<<u<<endl;
            cl=b[0].x.X+1;
            tl=b[0].y.X+b[0].z.X+4+b[1].z.X+b[2].z.X;
            soln.clear();
            soln.pb({b[0].y.Y,b[0].z.Y});
            soln.pb({b[1].z.Y,b[2].z.Y});
        }
        return;
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
    fo(i,n-1)
    {
        cin>>l>>r;
        a[l].pb(r);
        a[r].pb(l);
    }
    dfs0(1,0);
    ph[1]={-10,1};
    dfs1(1,0);
    dfs(1,0);
    // cerr<<"cl "<<cl<<" tl "<<tl<<endl;
    // assert((lli)soln.size()==2);
    // cerr<<"soln size "<<(lli)soln.size()<<endl;
    
    cout<<soln[0].X<<" "<<soln[1].Y<<endl;
    cout<<soln[0].Y<<" "<<soln[1].X<<endl;
}   aryanc403();
    return 0;
}