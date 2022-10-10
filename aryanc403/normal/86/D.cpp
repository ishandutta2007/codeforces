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

const lli sz = 1000;

bool cmp(const pair< lli, ii > &a,const pair< lli, ii > &b)
{
    
    if(a.Y.X/sz!=b.Y.X/sz)
        return a.Y.X<b.Y.X;
    
    if((a.Y.X/sz)&1)
        return a.Y.Y>b.Y.Y;
    
    return a.Y.Y<b.Y.Y;;
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;
    lli T,n,i,m,j,k,in,cnt,l,r,val[200005],freq[1000005];
    vi a;
    vector < pair< lli, ii > > q;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
    
    scanf(" %lld %lld",&n,&T);
    a.clear();a.reserve(n);
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
    }
    fo(i,T)
    {
        scanf(" %lld %lld",&l,&r);
        q.pb(mp(i,mp(l-1,r-1)));
    }
    
    sort(q.begin(),q.end(),cmp);
    cnt=0;
    l=0;r=-1;
    fo(i,T)
    {
        while(r<q[i].Y.Y)
        {
            r++;
            freq[a[r]]++;
            cnt+=a[r]*(2*freq[a[r]]-1);
        }
        
        while(l>q[i].Y.X)
        {
            l--;
            freq[a[l]]++;
            cnt+=a[l]*(2*freq[a[l]]-1);
        }
        
        while(r>q[i].Y.Y)
        {
            freq[a[r]]--;
            cnt-=a[r]*(2*freq[a[r]]+1);
            r--;
        }
        
        while(l<q[i].Y.X)
        {
            freq[a[l]]--;
            cnt-=a[l]*(2*freq[a[l]]+1);
            l++;
        }
        
        val[q[i].X]=cnt;
    }
    
    fo(i,T)
        cout<<val[i]<<endl;
    
    aryanc403();
    return 0;
}