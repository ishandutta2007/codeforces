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
    LLI T,n,in,i,m,j,k,cnt;
    vector <LLI> primes;
    vector <LLI> :: iterator it;
bool p[31627];

void pre(LLI n)
{
    p[0]=p[1]=true;
    cnt=0;
    for(LLI i=2;i<=n;++i)
    {
        if(p[i])
            continue;
        primes.pb(i);
        cnt++;
        for(LLI j=i*i;j<=n;j+=i)
        {
            p[j]=true;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LLI p,y;
    bool ans;
    cin>>p>>y;
    pre((LLI)sqrt(y)+1);
    for(;y>p;y--)
    {
        ans=true;
        for(k=0;k<cnt&&primes[k]<=p;++k)
        {
            if(y%primes[k]==0)
            {
                ans=false;
                break;
            }
            /*if(y/primes[k]<=p&&y%(y/primes[k])==0)
            {
                ans=false;
                break;
            }*/
        }
        
        if(ans)
        {
            cout<<y;
            return 0;
        }
        
    }
    //if(check(p,y))
    {
        cout<<-1;
        //return 0;
    }
    return 0;
}