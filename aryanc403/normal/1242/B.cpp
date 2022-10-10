//Ref - http://codeforces.com/contest/920/submission/44377532
/************************************************************************************************************************************************************************************
  *                                                                                                                                                                                  *
   *                                                                                                                                                                                  *
    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
                 *                                                                                                                                                                                  *
                  *                                                                                                                                                                                  *
                   ************************************************************************************************************************************************************************************/
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

void add( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,1));
    else                    jt->Y++;
}

void del( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y==1)            m.erase(jt);
    else                    jt->Y--;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l,r,x,y;
    set<lli> a[200005];
    vi ans;
    vi :: iterator it;
    string s;
    lli id[200005];
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

lli root(lli n)
{
    if(id[n]==n)
        return n;
    return id[n]=root(id[n]);
}

void merge(lli x,lli y)
{
    // cout<<"Merging "<<x<<" "<<y<<endl;
    // x=root(x);
    y=root(y);
    if((lli)a[x].size()>(lli)a[y].size())
        a[x].swap(a[y]);
    id[y]=x;
    set<lli> z;
    for(auto &t:a[x])
    {
        if(a[y].find(t)!=a[y].end())
            z.insert(t);
    }
    a[x].swap(z);
    // a[y].clear();
    //I don't know why commenting here resulted from WA to AC.
    //In my opinion it makes no difference.
}

void dbg()
{
    lli i;
    repA(i,1,n)
        cout<<i<<" : "<<root(i)<<endl;
    repA(i,1,n)
    {
        if(i==root(i))
        {
            cout<<i<<" : ";
            for(auto &x:a[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cin>>T;while(T--)
{

    cin>>n>>m;
    repA(i,1,n)
        id[i]=i;
    
    fo(i,m)
    {
        cin>>x>>y;
        a[x].insert(y);
        a[y].insert(x);
    }

    for(lli rot=1;rot<=n;++rot)
    {
        if(rot!=root(rot))
            continue;
        for(lli i=rot+1;i<=n;++i)
        {
            if(a[rot].find(i)==a[rot].end())
                merge(rot,i);
        }
    }

    cnt=0;
    repA(i,1,n)
    {
        if(i==root(i))
        {
            cnt++;
            ans.pb(n-(lli)a[i].size());
        }
    }
    
    // dbg();
    
    cout<<cnt-1<<endl;return 0;
    sort(ans.begin(),ans.end());
    for(auto &x:ans)
        cout<<x<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}