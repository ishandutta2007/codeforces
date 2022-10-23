#include<iostream>
using namespace std;

const int N = 100005;

int a[N],pos[N];
char ans[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i),pos[a[i]]=i;
    ans[pos[n]] = 'B';
    for(int i=n-1;i>=1;--i)
    {
        ans[pos[i]] = 'B';
        for(int k=pos[i];k<=n;k+=i)
            if(a[k]>i && ans[k] == 'B')
                ans[pos[i]] = 'A';
        for(int k=pos[i];k>=1;k-=i)
            if(a[k]>i && ans[k] == 'B')
                ans[pos[i]] = 'A';
    }
    for(int i=1;i<=n;++i)
        printf("%c",ans[i]); 
}