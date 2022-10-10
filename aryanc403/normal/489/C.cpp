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
lli T,n,in,i,m,j,k,s;
vi a;
vi :: iterator it;

void largest(lli n,lli s)
{
    while(n--)
    {
        if(s>=9)
        {
            cout<<9;
            s-=9;
        }
        else
        {
            cout<<s;
            s=0;
        }
    }
    cout<<" ";
}

void smallest(lli n,lli s)
{

    if(n==1)
    {
        cout<<s<<" ";
        return;
    }

    if((n-1)*9+1>=s)
    {
        cout<<1;
        n--;
        s--;
    }
    else
    {
        cout<<s-(n-1)*9;
        s=(n-1)*9;
        n--;
    }

    while(n--)
    {
        if((n)*9>=s)
        {
            cout<<0;
            continue;
        }

        cout<<s-n*9;
        s=n*9;
    }
    cout<<" ";
}



int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;

    if(n==1&&s==0)
    {
        cout<<"0 0";
        return 0;
    }

    if(n*9<s||s<1)
    {
        cout<<"-1 -1";
        return 0;
    }
    smallest(n,s);
    largest(n,s);
    return 0;
}