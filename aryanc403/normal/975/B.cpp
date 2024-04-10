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

    LLI T,n,in,i,m,j;
    vector <LLI> a;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n=14;
    a.clear();
    a.reserve(14);
        fo(i,14)
        {
            scanf(" %lld",&in);
            a.pb(in);
        }
    
    LLI m=0,cnt,c;
    for(i=0;i<14;++i)
    {
        cnt=0;
        LLI b=a[i],sum;
        //scanf("%lld",&b);
        if(b<=0)
        continue;
        //printf("%lldi 0 ",i);
		sum=0;
        for(j=1;j<14;++j)
        {
            c=(b)/(14)+(b%14>=j);
            if((a[(i+j)%14]+c)%2==0)
            {
                cnt+=a[(i+j)%14]+c;
            }
            //printf("%lld ",c);
            //printf(" %lldi %lld ",(i+j)%14,a[(i+j)%14]+c);
            //b-=c;
            sum+=c;
        }
        //printf("\n");
        if((b/14)%2==0)
        cnt+=(b)/(14);
        //printf(" %lldsum %lldb\n",sum,b);
        m=max(m,cnt);
    }
    cout<<m;
    return 0;
}