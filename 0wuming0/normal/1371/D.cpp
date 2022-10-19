#include"bits/stdc++.h"
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        char a[305][305]={0};
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]='0';
        int x=-1,y=-1;
        if(k%n==0)printf("0\n");
        else printf("2\n");
        while(k--)
        {
            x++;y++;
            x%=n;y%=n;
            if(a[x][y]=='1')x=(x+1)%n;
            a[x][y]='1';
        }
        for(int i=0;i<n;i++)printf("%s\n",a[i]);
    }
    return 0;
}