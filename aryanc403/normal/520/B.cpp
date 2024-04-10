/************************************************************************************************************************************************************************************
 *  *                                                                                                                                                                                  *
 *   *                                                                                                                                                                                  *
 *    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
 *     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
 *      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
 *       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
 *        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
 *         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
 *          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
 *           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
 *            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
 *             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
 *              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
 *               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
 *                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
 *                 *                                                                                                                                                                                  *
 *                  *                                                                                                                                                                                  *
 *                   ************************************************************************************************************************************************************************************/

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
lli T,n,in,i,m,j,k;

class cmp
{
    public:
        lli operator () (const ii &a, const ii &b)
        {
            return a.Y<b.Y;

        }

};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    if(m<=n)
    {
        cout<<n-m;
        return 0;

    }
    vi a(m+1,INF);
    priority_queue < ii , vii , cmp > q;
    q.push(mp(n,0));
    a[n]=0;
    while(q.empty()==false)
    {
        ii b=q.top(); q.pop();
        //cout<<b.X<<" "<<b.Y<<endl;
        if(b.X==m)
            break;

        if(2*(b.X)>=m)
            a[m]=min(a[m],2*(b.X)-m+b.Y+1);
        else if(2*(b.X)==m||a[2*(b.X)]>b.Y+1)
        {
            a[2*(b.X)]=min(b.Y+1,a[2*(b.X)]);
            q.push(mp(2*(b.X),a[2*(b.X)]));

        }
        if(((b.X)-1>=0&&a[(b.X)-1]>b.Y+1)||b.X-1==m)
        {
            a[(b.X)-1]=min(b.Y+1,a[(b.X)-1]);
            q.push(mp((b.X)-1,a[(b.X)-1]));

        }

    }
    printf("%lld\n",a[m]);
    return 0;

}