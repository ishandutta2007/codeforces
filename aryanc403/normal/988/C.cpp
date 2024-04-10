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
    lli T,n,in,i,m,j,k;
    vi a;
    vector < pair< lli, pair<lli,lli> > > b;//sum,seq no,rmv no
    vi :: iterator it;
bool cmp(const pair< lli, pair<lli,lli> > &a,const pair< lli, pair<lli,lli> > &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y.X<b.Y.X)||(a.X==b.X&&a.Y.X==b.Y.X&&a.Y.Y<b.Y.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    lli N=0;
    fo(i,k)
    {
        lli sum=0;
        cin>>n;
        N+=n;
        a.clear();
        a.reserve(n);
        fo(j,n)
        {
            cin>>in;
            sum+=in;
            a.pb(in);
        }
        
        fo(j,n)
        {
            b.pb(mp(sum-a[j],mp(i+1,j+1)));
        }
    }
    
    sort(b.begin(),b.end(),cmp);
    N--;
    fo(i,N)
    {
        if(b[i].X==b[i+1].X&&b[i].Y.X!=b[i+1].Y.X)
        {
            cout<<"YES"<<endl;
            cout<<b[i].Y.X<<" "<<b[i].Y.Y<<endl;
            cout<<b[i+1].Y.X<<" "<<b[i+1].Y.Y<<endl;
            return 0;
        }
    }
    cout<<"NO";
    
    return 0;
}