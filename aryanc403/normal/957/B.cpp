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
#define MAX 100002
#define MOD 1000000007

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j,k,p,a,b;
    bool row[52],col[52],r[52],c[52];
    string s[52];
    vector <LLI> :: iterator it;

void solve()
{
    bool f=false;
    for(LLI i=0;i<n;++i)
    {
        for(LLI j=0;j<m;++j)
        {
            if(r[i]||c[j])
            if(s[i][j]=='#')
            {
                if(r[i]==false||c[j]==false)
                {
                    //printf("%lldi %lldj added\n",i,j);
                    f=true;
                    r[i]=c[j]=true;
                }
            }
        }
    }

    if(f)
        solve();
}

bool check()
{
    for(LLI i=0;i<n;++i)
    {
        for(LLI j=0;j<m;++j)
        {
            if(r[i]&&c[j])
            {
                if(s[i][j]=='.')
                {
                    //printf("dot at %lld %lldj\n",i,j);
                    return false;
                }
            }
        }
    }
    return true;
}

bool markfalse()
{
    for(LLI i=0;i<n;++i)
    {
        if(r[i])
        {
            if(row[i]==false)
            {
                //printf("%lldi rowfalse",i);
                return false;
            }
            row[i]=false;
        }
    }

    for(LLI i=0;i<m;++i)
    {
        if(c[i])
        {
            if(col[i]==false)
            {
                //printf("%lldi col false",i);
                return false;
            }
            col[i]=false;
        }
    }
    return true;
}
void pass()
{
    for(LLI i=0;i<n;++i)
    {
        if(r[i])
        {
            printf("row %lld true\n",i);
        }
    }
    for(LLI i=0;i<m;++i)
    {
        if(c[i])
        {
            printf("col %lld true\n",i);
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        cin>>s[i];
        row[i]=true;
    }
    for(i=0;i<m;++i)
        col[i]=true;

    for(LLI i=0;i<n;++i)
    {
        for(LLI j=0;j<m;++j)
        {
            if(s[i][j]=='#'&&row[i]&&col[j])
            {
                for(LLI x=0;x<n||x<m;++x)
                    r[x]=c[x]=false;
                r[i]=c[j]=true;
                //printf("\nNew Pass %lldi %lldj\n",i,j);
                solve();
                //pass();
                if(check()==false)
                {
                    cout<<"No";
                    return 0;
                }
                if(markfalse()==false)
                {
                    cout<<"No";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes";
    return 0;
}