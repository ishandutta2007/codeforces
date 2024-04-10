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
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
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
const lli mod = 998244353L;

    lli T,n,i,m,j,k,in,cnt,l;
    vi a;
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

lli po(lli a,lli p)
{
    if(p==0)
        return 1;
    lli c= po(a,p/2);
    c=(c*c)%mod;
    if(p%2)
        c=(c*a)%mod;
    return c;
}

lli fac[1000005],inv[1000005];

void pre()
{
    lli i;
    fac[0]=1;
    for(i=1;i<=1000000;++i)
        fac[i]=(fac[i-1]*i)%mod;
    inv[1000000]=po(fac[1000000],mod-2);
    for(i=1000000-1;i>=0;i--)
        inv[i]=(inv[i+1]*(i+1))%mod;
}

lli nCr(lli n,lli r)
{
    if(r<0||r>n)
        return 0;
    lli c=(fac[n]*inv[r])%mod;
    c=(c*inv[n-r])%mod;
    return c;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<po(3,3)<<endl;
    cin>>n;
    pre();
    lli ans=0;
    lli sgn=1;
    //cout<<inv[0]<<"\n\n";
    for(i=1;i<=n;++i,sgn=-sgn)
    {
        ans+=sgn*(nCr(n,i)*po(3,(n*n-n*i+i)%(mod-1)))%mod;
        ans%=mod;
        //cout<<sgn*(nCr(n,i)*po(3,(n*n-n*i+i)%(mod-1)))%mod<<endl;
    }
    ans*=2;
    ans%=mod;
    sgn=1;
    
    //cout<<ans<<endl;
    
    if(n%2)
        sgn=-1;
    for(i=0;i<n;++i,sgn=-sgn)
    {
        lli val=0;
        val=po(3,i*n%(mod-1))-po( po(3,i) -1 ,n);
        val%=mod;
        val*=3*nCr(n,i);
        val%=mod;
        ans+=sgn*val;
        ans%=mod;
    }


    cout<<(ans+mod)%mod;
    aryanc403();
    return 0;
}