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
    lli T,n,in,i,j,k;
    map <lli,lli> m;
    map <lli,lli> :: iterator it,jt,kt;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    lli ma=-INF,mi=INF;
    fo(i,n)
    {
        cin>>in;
        m.insert(mp(in,i+1));
        ma=max(ma,in);
        mi=min(mi,in);
    }
    pair <lli, pair<lli,lli> > ans,p;
    ans=mp(1,mp(ma,ma));
    ma=INF;
    for(it=m.begin();it!=m.end();++it)
    {
        //cout<<it->X<<endl;
        for(j=0;j<31;++j)
        {
            //cout<<(1L<<j)<<endl;
            jt=m.find(it->X+(1L<<j));
            if(jt!=m.end())
            {
                ans=mp(2,mp(it->X,jt->X));
                {
                    kt=m.find(jt->X+(1L<<j));
                    if(kt!=m.end())
                    {
                        cout<<3<<endl;
                        cout<<it->X<<" "<<jt->X<<" "<<kt->X;
                        return 0;
                    }
                }
            }
        }
    }
    
    if(ans.X==1)
    {
        cout<<ans.X<<endl<<ans.Y.X;
    }
    else
    {
        cout<<ans.X<<endl<<ans.Y.X<<" "<<ans.Y.Y;
    }
    
    return 0;
}