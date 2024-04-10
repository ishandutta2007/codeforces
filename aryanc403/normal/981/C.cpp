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
    lli T,n,in,i,m,j,k,x,y,cnt[100005],cntb[100005],ans,par[100005],root,root1;
    vi a[100005],tree[100005];
    vii vertex,ver;
    vi :: iterator it;
    bool poss=true,vis[100005];

lli find(lli u,lli p)
{
    if(cnt[u]==1)
        return u;
    if(a[u][0]==p)
    {
        return find(a[u][1],u);
    }
    else
    {
        return find(a[u][0],u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    root=0;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
        //vertex.pb(mp(x,y));
        cnt[x]++;
        cnt[y]++;
        if(cnt[x]>2)
        {
            if(root==0||root==x)
            {
                root=x;
            }
            else
            {
                cout<<"No";
                return 0;
            }
        }
        x=y;
        if(cnt[x]>2)
        {
            if(root==0||root==x)
            {
                root=x;
            }
            else
            {
                cout<<"No";
                return 0;
            }
        }
    }
    if(root==0)
    {
        for(i=1;i<=n;++i)
        {
            if(cnt[i]==1)
            {
                root=i;
                break;
            }
        }
    }
    
    cout<<"Yes"<<endl;
    cout<<cnt[root]<<endl;
    
    for(lli i=0;i<cnt[root];++i)
    {
        cout<<root<<" "<<find(a[root][i],root)<<endl;
    }
    return 0;
}