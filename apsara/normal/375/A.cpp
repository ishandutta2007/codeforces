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
const int V=1000100;
char s[V];
int ct[20];
int md[V];
int a[4];
int cn[7];
int main()
{
    md[0]=1;
    for(int i=1;i<=1000000;i++)
    md[i]=md[i-1]*10%7;
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(ct,0,sizeof(ct));
        for(int i=0;i<n;i++)
        ct[s[i]-'0']++;
        ct[1]--;ct[6]--;ct[8]--;ct[9]--;
        a[0]=1;a[1]=6,a[2]=8,a[3]=9;
        memset(cn,0,sizeof(cn));
        do
        {
            int re=0;
            for(int i=0;i<4;i++)
            re*=10,re+=a[i];
            cn[re%7]=re;
        }while(next_permutation(a,a+4));
        int r=0;
        for(int i=9;i>=0;i--)
        {
            for(int j=0;j<ct[i];j++)
            r*=10,r+=i,r%=7;
        }
        //for(int i=0;i<7;i++)printf("%d\n",cn[i]);
        int ret=-1;
        for(int i=0;i<7;i++)
        if((i*md[n-4]+r)%7==0)
        {
            ret=cn[i];
            break;
        }
        printf("%d",ret);
        for(int i=9;i>=0;i--)
        {
            for(int j=0;j<ct[i];j++)
            printf("%d",i);
        }
        puts("");
    }
}