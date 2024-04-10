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

    lli T,n,i,m,j,k,in,cnt,l,q;
    vi a;
    ii ans[200005];
    vi :: iterator it;
    lli seq[800005];
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

void insert(lli root,lli l,lli r,lli idx,lli val)
{
    if(l>r||idx<l||r<idx)
        return;
    if(seq[root]==0)
        seq[root]=INF;
    if(l==r)
    {
        if(l==idx&&seq[root]>val)
            seq[root]=val;
        return;
    }
    //cout<<idx<<"idx "<<val<<"val "<<l<<"l r"<<r<<endl;
    if(seq[root]>val)
        seq[root]=val;
    lli m=l+((r-l)>>1);
    if(l<=idx&&idx<=m)
        insert(2*root,l,m,idx,val);
    if(m+1<=idx&&idx<=r)
        insert(2*root+1,m+1,r,idx,val);
}

lli query(lli root,lli l,lli r,lli L,lli R)
{
    if(l>r||R<l||r<L)
        return INF;
    //cout<<l<<"l r"<<r<<" "<<L<<"L R"<<R<<" "<<root<<"root seq"<<seq[root]<<endl;
    if(seq[root]==0)
        seq[root]=INF;
    if(L<=l&&r<=R)
        return seq[root];
    lli m=l+((r-l)>>1);
    lli x,y;
    x=query(2*root,l,m,L,R);
    y=query(2*root+1,m+1,r,L,R);
    return x>y?y:x;
}

bool check()
{
    repA(j,1,q)
    {
        if(ans[j].X==0&&ans[j].Y==0)
            continue;
        //cout<<j<<" "<<query(1,1,n,ans[j].X,ans[j].Y)<<endl;
        if(query(1,1,n,ans[j].X,ans[j].Y)<j)
            return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;//scanf(" %lld %lld",&n,&q);
    a.clear();a.reserve(n+1);
    bool fl=true;
    lli zP=0;
    m=0;
    a.pb(0);
    fo(i,n)
    {
        cin>>in;//scanf(" %lld",&in);
        a.pb(in);
        if(in>m)
            m=in;
        if(in==0)
        {
            m=q;
            zP=i+1;
            continue;
        }
        insert(1,1,n,i+1,in);
        if(in==q)
            fl=false;
        if(ans[in].X==0)
            ans[in].X=i+1;
        if(ans[in].Y<=i)
            ans[in].Y=i+1;
    }
    
    if(m!=q||check()==false)
    {
        cout<<"NO";
        return 0;
    }
    
    if(fl)
    {
        if(zP)
            a[zP]=q;
        else
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    lli pvr=0;
    repA(i,1,n)
    if(a[i])
    {
        pvr=a[i];
        break;
    }
    repA(i,1,n)
    {
        cout<<(a[i]?(pvr=a[i]):pvr)<<" ";
    }
    aryanc403();
    return 0;
}