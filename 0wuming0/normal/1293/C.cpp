#include"bits/stdc++.h"
using namespace std;
int n,q;
int a[3][100005];
int sum=0;
int con(int x,int y)
{
    int s=0;
            if(y-1>=1&&a[x][y-1]==0&&(a[x^1][y-1]==1||a[x^1][y]==1))s++;
            if(y+1<=n&&a[x][y+1]==0&&(a[x^1][y+1]==1||a[x^1][y]==1))s++;
            return s;
}
int main()
{

    cin>>n>>q;
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);x--;
        if(a[x][y]==0)
        {
            sum+=con(x,y);
            a[x][y]=1;
        }
        else
        {
            sum-=con(x,y);
            a[x][y]=0;
        }
        //cout<<sum;
        if(sum==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}