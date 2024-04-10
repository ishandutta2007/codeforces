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
int a,b;
int main()
{
    while(~scanf("%d%d",&a,&b))
    {
        int ret=a;
        int re=a;
        while(1)
        {
            if(re<b)break;
            int tmp=re/b;
            ret+=tmp;
            re=re%b+tmp;
        }
        printf("%d\n",ret);
    }
}