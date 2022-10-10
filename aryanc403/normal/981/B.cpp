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
    lli T,n[2],in,i,m,j,k,x,y;
    vii a[2];
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    T=2;
    while(T--)
    {
        scanf(" %lld",&n[T]);
        a[T].clear();
        a[T].reserve(n[T]);
        fo(i,n[T])
        {
            scanf(" %lld %lld",&x,&y);
            a[T].pb(mp(x,y));
        }
        sort(a[T].begin(),a[T].end(),cmp);
    }
    
    i=0;
    j=0;
    lli c=0;
    while(i<n[0]||j<n[1])
    {
        if(i==n[0])
        {
            c+=a[1][j].Y;
            j++;
        }
        else if(j==n[1])
        {
            c+=a[0][i].Y;
            i++;
        }
        else if(a[0][i].X==a[1][j].X)
        {
            c+=max(a[0][i].Y,a[1][j].Y);
            i++;
            j++;
        }
        else if(a[0][i].X<a[1][j].X)
        {
            c+=a[0][i].Y;
            i++;
        }
        else
        {
            c+=a[1][j].Y;
            j++;
        }
    }
    printf("%lld",c);
    return 0;
}