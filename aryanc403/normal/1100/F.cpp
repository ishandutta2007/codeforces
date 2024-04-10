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
    string s;
    vi a,final[2000005];
    vector< pair<ii,lli> > qur;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void merge(vi &ans,const vi &b)
{
    for(auto x:b)
        ans.pb(x);
    lli i,j,k;
    lli sz=(lli)ans.size();
    lli l=0;
    repD(k,20,0)
    {
        repA(j,l,sz-1)
        {
            if(ans[j]&(1<<k))
                break;
        }
        if(j==sz)
            continue;
        swap(ans[l],ans[j]);
        repA(i,0,sz-1)
        {
            if(i!=l&&ans[i]&(1<<k))
                ans[i]^=ans[l];
        }
        l++;
    }
    if(!ans.empty())
        sort(ans.rbegin(),ans.rend());
    while(!ans.empty()&&*ans.rbegin()==0)
        ans.pop_back();
}

vi gauss[500005];
lli ans[500005];

void add(vi &ans,lli x)
{
    lli k;
    // vi tmp(ans);
    // tmp.pb(x);
    
    // cout<<"Adding "<<x<<endl;
    // for(auto x:ans)
    //     cout<<x<<" ";cout<<endl;
    for(auto y:ans)
    {
        x=min(x,x^y);
    }
    if(x)
    {
        for(auto &y:ans)
            y=min(y,y^x);
        ans.pb(x);
    }
    // cout<<"Final add result"<<endl;
    // for(auto x:ans)
    //     cout<<x<<" ";cout<<endl;
    // merge(tmp,tmp);
    // cout<<"Merge result"<<endl;
    // for(auto x:tmp)
    //     cout<<x<<" ";cout<<endl<<endl;
}

void solve(vector< pair<ii,lli> > &q,lli l,lli r)
{
    vi gs;
    lli i;
    if(r-l<=20)
    {
        vi tmp;
        tmp.clear();
        for(auto x:q)
        {
            gs.clear();
            repA(i,x.X.X,x.X.Y)
                add(gs,a[i]);
            for(auto y:gs)
                ans[x.Y]^=y;
            continue;
            gs.clear();
            repA(i,x.X.X,x.X.Y)
                gs.pb(a[i]);
            merge(gs,tmp);
            for(auto y:gs)
            {
                ans[x.Y]^=y;
            }
            if(ans[x.Y])
            {
                cout<<"assert failed"<<ans[x.Y]<<endl;
                exit(0);
            }
        }
        return;
    }
    
    lli m=(l+r)/2;
    gs.clear();
    repD(i,m,l)
    {
        // gauss[i].clear();gauss[i].pb(a[i]);
        // merge(gauss[i],gs);
        // gs=gauss[i];
        add(gs,a[i]);
        gauss[i]=gs;
    }
    
    gs.clear();
    repA(i,m+1,r)
    {
        // gauss[i].clear();gauss[i].pb(a[i]);
        // merge(gauss[i],gs);
        // gs=gauss[i];
        add(gs,a[i]);
        gauss[i]=gs;
    }
    
    vector< pair<ii,lli> > lef,rgt;
    lef.clear();rgt.clear();
    for(auto x:q)
    {
        if(x.X.Y<=m)
            lef.pb(x);
        else if(x.X.X>m)
            rgt.pb(x);
        else
        {
            gs.clear();
            gs=gauss[x.X.X];
            merge(gs,gauss[x.X.Y]);
            ans[x.Y]=0;
            for(auto y:gs)
                ans[x.Y]^=y;
        }
    }
    q.clear();
    // repA(i,l,r)
        // gauss[i].clear();
    solve(lef,l,m);
    solve(rgt,m+1,r);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    a.clear();a.reserve(n+1);
    a.pb(0);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }
    
    lli q;
    cin>>q;
    fo(i,q)
    {
        cin>>l>>r;
        qur.pb({{l,r},i});
    }
    solve(qur,1,n);
    fo(i,q)
        cout<<ans[i]<<endl;
}   aryanc403();
    return 0;
}