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
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k,l;
    vi a;
    vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld %lld %lld",&n,&k,&l);
        T=n*k;
        a.clear();
        a.reserve(T);
        fo(i,T)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
    sort(a.begin(),a.end());
    
    if(a[n-1]-a[0]>l)
    {
        cout<<0;
        return 0;
    }
    T=upper_bound(a.begin(),a.end(),a[0]+l)-a.begin();
    //cout<<T<<endl;
    lli sum=0;
    bool fur=false;
    lli N=n;
    for(i=1;i<=N;i++)
    {
        n--;
        if(T-i*k>=n)
        {
            sum+=a[(i-1)*k];
            //cout<<(i-1)*k<<" ";
            //cout<<a[(i-1)*k]<<" ";
        }
        else
        {
            sum+=a[(i-1)*k];
            //cout<<(i-1)*k<<" ";
            //cout<<a[(i-1)*k]<<" ";
            fur=true;
            break;
        }
    }
    //cout<<n<<endl;
    if(fur)
    while(n>0&&n--)
    {
        T--;
        sum+=a[T];
        //cout<<T<<" ";
        //cout<<a[T]<<" ";
    }
    cout<<sum;
    return 0;
}