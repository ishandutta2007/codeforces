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
    vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b,s;
    cin>>s;
    //cout<<s;
    bool is;
    lli l=s.size();
    i=-1;
    while(i<l)
    {
        i++;
        j=0;
        is=true;
        while(i+j<l)
        {
            if(s[i+j]==44||s[i+j]==59)
                break;
            if(s[i+j]<'0'||s[i+j]>'9')
                is=false;
            j++;
        }
        
        if(s[i]=='0'&&j!=1)
        {
            is=false;
        }
        //cout<<s.substr(i,j)<<endl;
        if(is&&j)
        {
            a+=s.substr(i,j)+",";
        }
        else
        {
            b+=s.substr(i,j)+",";
        }
        
        //cout<<i<<" "<<i+j+1<<endl;
        //cout<<a<<"|"<<b<<endl;
        i+=j;
        //i+=(s[i]==46||s[i]==44||s[i]==59);
    }
    if(l=a.size())
    {
        cout<<'"'<<a.substr(0,l-1)<<'"'<<endl;
    }
    else
    {
        cout<<'-'<<endl;
    }
    
    if(l=b.size())
    {
        cout<<'"'<<b.substr(0,l-1)<<'"'<<endl;
    }
    else
    {
        cout<<'-'<<endl;
    }
    return 0;
}