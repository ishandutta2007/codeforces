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

    lli T,n,i,m,j,k,in,cnt,l,r,ans[1000005],x,y;
    vi a[1000005];
    vi :: iterator it;
    string s;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p,vi &arr,lli &m,lli &sz)
{
    lli mx;
    vi cld;
    lli cldsz,i,j;
    // vi :: reverse_iterator it,jt,frt;
    for(auto &v:a[u])
    {
        if(v==p)
            continue;
        cld.clear();
        mx=-1;
        cldsz=0;
        dfs(v,u,cld,mx,cldsz);
        // cout<<u<<" received "<<v<<" mx "<<mx<<" : ";
        // for(j=0;j<cldsz;++j)
        //     cout<<cld[j]<<" ";
        // cout<<endl;
        if(cldsz>sz)
        {
            arr.swap(cld);
            swap(mx,m);
            swap(sz,cldsz);
        }
        for(j=cldsz-1,i=sz-1;j>=0;j--,i--)
        {
            arr[i]+=cld[j];
            if(m==-1||(m>i&&arr[i]>arr[m])||(m<i&&arr[i]>=arr[m]))
                m=i;
        }
    }
    arr.pb(1);sz++;i=sz-1;
    if(m==-1||(m>i&&arr[i]>arr[m])||(m<i&&arr[i]>=arr[m]))
        m=i;
    ans[u]=sz-m-1;
    
    // cout<<"Dominant Array of "<<u<<" m"<<m<<" "<<sz<<"sz : ";
    // for(j=0;j<sz;j++)
    //     cout<<arr[j]<<" ";
    // cout<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cin>>T;while(T--)
{

    cin>>n;
    fo(i,n-1)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    vi cld;
    lli mx,cldsz;
    cld.clear();
    mx=-1;
    cldsz=0;
    dfs(1,0,cld,mx,cldsz);

        // cout<<0<<" received "<<1<<" mx "<<mx<<" : ";
        // for(j=0;j<cldsz;++j)
        //     cout<<cld[j]<<" ";
        // cout<<endl;


    repA(i,1,n)
        cout<<ans[i]<<endl;
}   aryanc403();
    return 0;
}