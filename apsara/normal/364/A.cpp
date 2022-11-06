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
const int V=4010;
const int mod=10000007;
struct Edge{int x,ct,ne;}e[mod];
int p[mod],K;
void init()
{
    memset(p,-1,sizeof(p));K=0;
}
void add(int x)
{
    int re=x%mod;
    for(int i=p[re];i!=-1;i=e[i].ne)
    if(e[i].x==x){e[i].ct++;return;}
    e[K].x=x;e[K].ct=1;e[K].ne=p[re];p[re]=K++;
}
int find(int x)
{
    int re=x%mod;
    for(int i=p[re];i!=-1;i=e[i].ne)
    if(e[i].x==x)return e[i].ct;
    return 0;
}
char s[V];
int A;
int main()
{
    while(~scanf("%d",&A))
    {
        scanf("%s",s);
        int n=strlen(s);
        LL ret=0;
        init();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=s[j]-'0';
                add(sum);
            }
        }
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=s[j]-'0';
                if(sum==0)
                {
                    if(A==0)
                    ret+=n*(n+1)/2;
                }
                else if(A%sum==0)
                ret+=find(A/sum);
            }
        }
        printf("%I64d\n",ret);
    }
    return 0;
}