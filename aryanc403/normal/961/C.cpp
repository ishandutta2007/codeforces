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

/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
#ifdef LOCAL_TEST
    freopen("in.txt","r",stdin);
#endif*/

    LLI T,n,in,i,m,j,k,a[100005],t;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    
    char s[4][n][102],b;
    LLI a[4][2];
    for(i=0;i<4;++i)
    {
        a[i][0]=a[i][1]=0;
        for(j=0;j<n;++j)
        {
            scanf(" %s",s[i][j]);
            //printf("%s\n",s[i][j]);
            for(k=0;k<n;++k)
            {
                if(s[i][j][k]-'0'==(j+k)%2)
                {
                    a[i][1]++;
                }
                else
                {
                    a[i][0]++;
                }
            }
        }
        scanf("%c",&b);
        //printf("%c",b);
    }
    
    for(i=0;i<4;++i)
    {
        for(j=0;j<3;++j)
        {
            if(a[j][0]>a[j+1][0])
            {
                a[j][0]=a[j][0]+a[j+1][0]-(a[j+1][0]=a[j][0]);
            }
            if(a[j][1]>a[j+1][1])
            {
                a[j][1]=a[j][1]+a[j+1][1]-(a[j+1][1]=a[j][1]);
            }
        }
    }
    //for(i=0;i<4;++i)
      //  printf("%lld %lld\n",a[i][0],a[i][1]);
        
    printf("%lld",a[0][0]+a[1][0]+a[0][1]+a[1][1]);
    return 0;
}