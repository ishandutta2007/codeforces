#include<iostream>
using namespace std;

const int N=100005;
int a[N];

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;++i)
        scanf("%d",a+i);

    auto f=[&](int x)
    {
        if(n/x<3)
            return ;
        for(int i=0;i<x;++i)
        {
            bool ans=1;
            for(int j=i;j<n;j+=x)
                ans &= a[j];
            if(ans)
            {
                printf("YES");
                exit(0);
            }
        }

    };

    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            f(i);
            f(n/i);
        }
    }
    printf("NO");
}