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
#define endl '\n'
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
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

class cmp
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return a > b;
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

    lli T,n,i,m,j,k,in,cnt,l;
    vi a,b;
    lli seg[1000005];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

void add(lli root,lli l,lli r,lli L,lli R)
{
    if(l>r||r<L||l>R)
        return;
    
    if(L<=l&&r<=R)
    {
        //cout<<"add "<<root<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
        seg[root]++;
        return;
    }
        
    lli m=l+(r-l)/2;
    add(2*root,l,m,L,R);
    add(2*root+1,m+1,r,L,R);
}

lli times(lli root,lli l,lli r,lli idx)
{
    if(l>r||r<idx||idx<l)
        return 0;
    if(l==r)
        return seg[root];
    lli m=l+(r-l)/2;
    return seg[root]+times(2*root,l,m,idx)+times(2*root+1,m+1,r,idx);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli q;
    scanf(" %lld %lld",&n,&q);
    a.clear();a.reserve(n);
    b.clear();b.reserve(n);
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
    }
    sort(a.rbegin(),a.rend());
    lli r;
    while(q--)
    {
        scanf(" %lld %lld",&l,&r);
        add(1,0,n-1,l-1,r-1);
    }
    lli sum=0;
    for(i=0;i<n;i++)
        b.pb(times(1,0,n-1,i));
    //cout<<times(1,0,n-1,0);
    sort(b.rbegin(),b.rend());
    //for(auto &x:b)
      //  cout<<x<<" ";
    for(i=0;i<n;i++)
        sum+=a[i]*b[i];
    cout<<sum;
    aryanc403();
    return 0;
}