#include"bits/stdc++.h"
#define ll long long
using namespace std;
int a[100007];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n,cmp);//for(int i=0;i<n;i++)cout<<a[i]<<endl;
    int ans=n/2+(n%2==0?(-1):0);
    cout<<ans<<endl;
    int l=n-ans,r=0;
    for(int i=0;i<n;i++)
    {
        if((i%2)&&i!=n-1){printf("%d",a[l]);l++;}
        else{printf("%d",a[r]);r++;}
        if(i==n-1)putchar(10);
        else putchar(' ');
    }
    return 0;
}
/*
6
1 2 3 4 5 6
*/