#include"bits/stdc++.h"
using namespace std;
int main()
{
    int a[100005]={0};
    int num[100005]={0};
    int n,m,now=0;
    cin>>n>>m;
    num[0]=n;
    while(m--)
    {
        int t;
        scanf("%d",&t);
        num[a[t]]--;
        if(now==a[t]&&num[a[t]]==0)
        {
            putchar('1');
            now++;
        }
        else putchar('0');
        a[t]++;
        num[a[t]]++;
    }
    putchar(10);
    return 0;
}