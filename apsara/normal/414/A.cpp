#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
const int P=1000000007;
int n,K;
int main()
{
    while(~scanf("%d%d",&n,&K))
    {
        if(n==1&&K==0)
        {
            puts("1");
            continue;
        }
        if(n<2||n/2>K)
        {
            puts("-1");
            continue;
        }
        int x=K-n/2+1;
        printf("%d",x);
        printf(" %d",2*x);
        int pr=3;
        for(int i=1;i<n/2;i++)
        {
            if(x==pr||x==pr+1)pr+=2;
            if(2*x==pr||2*x==pr+1)pr+=2;
            printf(" %d %d",pr,pr+1);
            pr+=2;
        }
        if(n%2==1)printf(" 1000000000");puts("");
    }
}