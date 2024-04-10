#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[53][53]={0};
    int ans[2505][2]={0},sum=0;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(a[i][j])
        {
            if(i>0&&j>0&&a[i-1][j]&&a[i][j-1]&&a[i-1][j-1])ans[sum][0]=i,ans[sum][1]=j,sum++;
            else if(i>0&&j!=m-1&&a[i-1][j]&&a[i-1][j+1]&&a[i][j+1])ans[sum][0]=i,ans[sum][1]=j+1,sum++;
            else if(i!=n-1&&j>0&&a[i][j-1]&&a[i+1][j-1]&&a[i+1][j])ans[sum][0]=i+1,ans[sum][1]=j,sum++;
            else if(i!=n-1&&j!=m-1&&a[i+1][j+1]&&a[i+1][j]&&a[i][j+1])ans[sum][0]=i+1,ans[sum][1]=j+1,sum++;
            else
            {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",sum);
    for(int i=0;i<sum;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}
/*

*/