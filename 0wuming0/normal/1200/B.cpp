#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"math.h"
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,k;
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&k);
        int a[105]={0};
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int i;
        for(i=1;i<n;i++)
        {
            m+=a[i]-a[i+1];
            m+=min(k,a[i+1]);
            if(m<0)break;
        }
        if(i==n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*

*/