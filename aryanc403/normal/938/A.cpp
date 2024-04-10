//for(auto a: x);
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
    vii t;
    vi a;
    vi :: iterator it;

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>n;
    cin>>s;
    lli cnt=0;
    
    fo(i,n)
    {
        if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'))
        {
            if(cnt==0)
            {
                cout<<s[i];
            }
            cnt++;
        }
        else
        {
            cnt=0;
            cout<<s[i];
        }
    }
    
    
    return 0;
}