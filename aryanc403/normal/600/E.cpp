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
 *                    hello                                                                                                                                                              *
 ************************************************************************************************************************************************************************************/

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#pragma GCC optimize ("-ffloat-store")
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
    lli T,n,in,i,m,j,k,clr[100005],ans[100005];
    vi a[100005];
void dfs(lli u,lli p,map <lli,lli> &m,lli &mx)
{
    map <lli,lli> b;
    lli bx;
    map <lli,lli> :: iterator jt;
    ans[u]=0;
    mx=0;
    for(auto &v:a[u])
    {
        if(v==p)
            continue;
        bx=0;b.clear();
        dfs(v,u,b,bx);
        if((lli)b.size()>(lli)m.size())
        {
            m.swap(b);
            swap(mx,bx);
            ans[u]=ans[v];
        }
        
        for(auto &x:b)
        {
            jt=m.find(x.X);
            if(jt==m.end())
                m.insert(x);
            else
                jt->Y+=x.Y;
            jt=m.find(x.X);
            if(jt->Y>mx)
            {
                ans[u]=x.X;
                mx=jt->Y;
            }
            else if(jt->Y==mx)
                ans[u]+=x.X;
        }
    }
        
    jt=m.find(clr[u]);
    if(jt==m.end())
        m.insert({clr[u],1});
    else
        jt->Y++;
    jt=m.find(clr[u]);
    if(jt->Y>mx)
    {
        ans[u]=clr[u];
        mx=jt->Y;
    }
    else if(jt->Y==mx)
        ans[u]+=clr[u];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>clr[i];
    }
    lli x,y;
    for(i=1;i<n;++i)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    map <lli,lli> m;
    i=0;
    dfs(1,0,m,i);
    for(i=1;i<=n;++i)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}