//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j,k;
    vector <LLI> a;
    vector <LLI> :: iterator it;

char s[105][105];

LLI CNT(LLI r,LLI c)
{
    LLI cnt=0;
    if(r-1>=0&&c-1>=0&&r-1<n&&c-1<m)
    {
        cnt+=(s[r-1][c-1]=='*');
    }
    if(r-1>=0&&c>=0&&r-1<n&&c<m)
    {
        cnt+=(s[r-1][c]=='*');
    }
    if(r-1>=0&&c+1>=0&&r-1<n&&c+1<m)
    {
        cnt+=(s[r-1][c+1]=='*');
    }
    if(r>=0&&c-1>=0&&r<n&&c-1<m)
    {
        cnt+=(s[r][c-1]=='*');
    }
    if(r>=0&&c+1>=0&&r<n&&c+1<m)
    {
        cnt+=(s[r][c+1]=='*');
    }
    if(r+1>=0&&c-1>=0&&r+1<n&&c-1<m)
    {
        cnt+=(s[r+1][c-1]=='*');
    }
    if(r+1>=0&&c>=0&&r+1<n&&c<m)
    {
        cnt+=(s[r+1][c]=='*');
    }
    if(r+1>=0&&c+1>=0&&r+1<n&&c+1<m)
    {
        cnt+=(s[r+1][c+1]=='*');
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    fo(i,n)
    {
        cin>>s[i];
        //cout<<s[i];
    }
    
    for(LLI i=0;i<n;++i)
    {
        for(LLI j=0;j<m;++j)
        {
            if(s[i][j]=='*')
                continue;
            
            LLI cnt=CNT(i,j);
            
            if((s[i][j]=='.'&&cnt!=0)||(s[i][j]!='.'&&s[i][j]-'0'!=cnt))
            {
                cout<<"NO";
                //cout<<cnt<<" "<<i<<" "<<j;
                return 0;
            }
            
        }
    }
    cout<<"YES";
    return 0;
}