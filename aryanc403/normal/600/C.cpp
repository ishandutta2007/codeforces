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
    lli cnt[26];
    vi :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    lli l=s.size();
    char c='\0';
    fo(i,l)
        cnt[s[i]-'a']++;
    string a;
    fo(i,26)
    {
        if(cnt[i]%2)
        {
            for(j=25;j>i;j--)
            {
                if(cnt[j]%2)
                    break;
            }
            
            if(j!=i)
            {
                cnt[j]--;
                cnt[i]++;
            }
            else
            {
                c=i+'a';
                cnt[i]--;
            }
        }
    }
    
    //cout<<"|"<<c<<"|";
    fo(i,26)
    {
        j=cnt[i]/2;
        while(j--)
            cout<<(char)(i+'a');
    }
    if(c)
    {
        cout<<c;
    }
    fo(i,26)
    {
        j=cnt[25-i]/2;
        while(j--)
            cout<<(char)(25-i+'a');
    }
    return 0;
}