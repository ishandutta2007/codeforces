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
lli T,n,in,i,m,j,k;
vi a;
vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    a.clear();
    a.reserve(n);
    lli sum=0;
    fo(i,n)
    {
        scanf(" %lld",&in);
        a.pb(in);
        sum+=in;
    }
    //cout<<"sum"<<sum<<endl;
    if(sum%3)
    {
        cout<<0;
        return 0;
    }
    sum=sum/3;
    lli c[4]={0,0,0,0},s=0,ans=0;
    //cout<<sum<<endl;
    fo(i,n)
    {
        s+=a[i];
        if(sum==0)
        {
            if(s==0)
            c[3]++;
            continue;
        }
        if(s==1*sum)
        {
            c[0]++;
        }
        if(s==2*sum)
        {
            ans+=c[0];
        }
        //cout<<i<<"exit"<<endl;
        //cout<<a[i]<<" ";
    }
    //cout<<endl;
    if(sum)
        cout<<ans;
    else
    {
        cout<<(c[3]-1)*(c[3]-2)/2;
    }
    return 0;
}