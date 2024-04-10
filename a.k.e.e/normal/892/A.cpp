#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=100005;

int n,b[MAXN];

int main()
{
    scanf("%d",&n);
    long long sum=0,max1=0,max2=0;
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>max1)
        {
            max2=max1;
            max1=x;
        }
        else if(x>max2)
            max2=x;
    }
    if(max2+max1>=sum)printf("YES\n");
    else printf("NO\n");
    //system("pause");
    return 0;
}