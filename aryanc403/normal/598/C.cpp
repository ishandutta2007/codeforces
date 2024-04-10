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

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef long double ld;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
#define PI 3.1415926535897932384626433832795
lli n,in,i,m,j,k,x,y;
    vector < pair < pair < lli,lli > , lli > > a;
    vi :: iterator it;

ld angle(const pair < pair < lli,lli > , lli > &a)
{
    ld d = atan2((ld)a.X.Y,(ld)a.X.X);
    if(d<0)     d=d+2*PI;
    return d;
}

bool cmp(const pair < pair < lli,lli > , lli > &a,const pair < pair < lli,lli > , lli > &b)
{
    return angle(a)<angle(b);
}

void solve()
{
    scanf(" %lld",&n);
    a.clear();
    a.reserve(n);
    fo(i,n)
    {
        scanf(" %lld %lld",&x,&y);
        a.pb(mp(mp(x,y),i+1));
    }
    sort(a.begin(),a.end(),cmp);
    
    //fo(i,n)
    {
      //cout<<angle(a[i])<<" ";
    }
    //cout<<endl<<endl;
    pair <lli,ld> m,p;
    m=mp(0,2*PI);
    for(i=0;i<n-1;++i)
    {
        p=mp(i,angle(a[i+1])-angle(a[i]));
        if(p.Y<m.Y)
            m=p;
    }
    p=mp(i,angle(a[0])-angle(a[n-1])+2*PI);
    if(p.Y<m.Y)
        m=p;
    printf("%lld %lld",a[m.X].Y,a[(m.X+1)%n].Y);
    //cout<<endl<<"hello  "<<m.Y<<endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli T=1;
    //scanf(" %lld",&T);
    while(T--)
        solve();
    return 0;
}