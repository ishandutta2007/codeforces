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
    lli T,n,in,i,m,j,k,r,s,d,x,y,p;
    vi :: iterator it;

//typedef ii mytype;
class cmp
{
    public:
    lli operator () (const ii &a, const ii &b)
    {
        return a.Y>b.Y;
    }
};

priority_queue < ii , vii , cmp > a[100005];
vii cost(100005,mp(INF,-1));
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld %lld",&n,&r);
        fo(i,r)
        {
            scanf(" %lld %lld %lld",&x,&y,&p);
            a[x].push(mp(y,p));
            a[y].push(mp(x,p));
        }
        priority_queue < ii , vii , cmp > q;
        q.push(mp(1,0));
        cost[1]=mp(0,-1);
        while(q.empty()==false)
        {
            ii b=q.top(); q.pop();
            
            //cout<<b.X<<" "<<b.Y<<endl;
            
            if(cost[b.X].X<b.Y)
                continue;
            
            while(a[b.X].empty()==false)
            {
                ii c=a[b.X].top();a[b.X].pop();
                if(cost[c.X].X>b.Y+c.Y)
                {
                    cost[c.X]=mp(b.Y+c.Y,b.X);
                    q.push(mp(c.X,cost[c.X].X));
                }
            }
        }
    if(cost[n].Y==-1)
    {
        cout<<-1;
        return 0;
    }
    
    stack <lli> p;
    lli u=n;
    while(u!=-1)
    {
        p.push(u);
        u=cost[u].Y;
    }
    
    while(p.empty()==false)
    {
        cout<<p.top()<<" ";p.pop();
    }
    return 0;
}