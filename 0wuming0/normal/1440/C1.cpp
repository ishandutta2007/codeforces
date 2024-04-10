#include"bits/stdc++.h"
using namespace std;
int ans[10005][6],nn;
int a[105][105];
char s[105];
#define ch a[ans[nn][0]][ans[nn][1]]^=1;a[ans[nn][2]][ans[nn][3]]^=1;a[ans[nn][4]][ans[nn][5]]^=1
int solve(int i,int j)
{
    if(a[i][j]==0&&a[i+1][j]==0)return 0;
    int q=0;
    if(a[i][j]==1)ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    i++;
    if(a[i][j]==1)ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    i--;
    j++;
    ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    if(q==6){ch;nn++;return 0;}
    i++;
    ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    ch;nn++;return 0;
}
int solve2(int i,int j)
{
    if(a[i][j]==0&&a[i][j+1]==0)return 0;
    int q=0;
    if(a[i][j]==1)ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    j++;
    if(a[i][j]==1)ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    j--;
    i++;
    ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    if(q==6){ch;nn++;return 0;}
    j++;
    ans[nn][q]=i,ans[nn][q+1]=j,q+=2;
    ch;nn++;return 0;
}
int solve31(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
int solve32(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
int solve33(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
int solve34(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
int solve31(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
    ans[nn][0]=a1;ans[nn][1]=b1;ans[nn][2]=a2;ans[nn][3]=b2;ans[nn][4]=a3;ans[nn][5]=b3;
    ch;
    nn++;
    solve32(a2,b2,a3,b3,a4,b4,a1,b1);
    return 0;
}
int solve32(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
    ans[nn][0]=a1;ans[nn][1]=b1;ans[nn][2]=a4;ans[nn][3]=b4;ans[nn][4]=a3;ans[nn][5]=b3;
    ch;
    nn++;
    solve33(a2,b2,a3,b3,a4,b4,a1,b1);
    return 0;
}
int solve33(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{//cout<<a1<<b1<<a2<<b2<<a3<<b3<<endl;
    ans[nn][0]=a1;ans[nn][1]=b1;ans[nn][2]=a2;ans[nn][3]=b2;ans[nn][4]=a3;ans[nn][5]=b3;
    ch;
    nn++;
    return 0;
}
int solve34(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
    ans[nn][0]=a2;ans[nn][1]=b2;ans[nn][2]=a4;ans[nn][3]=b4;ans[nn][4]=a3;ans[nn][5]=b3;
    ch;
    nn++;
    solve31(a2,b2,a3,b3,a4,b4,a1,b1);
    return 0;
}
struct _
{
    int x;
    int y;
}p[4];
bool cmp(struct _ x,struct _ y)
{
    return a[x.x][x.y]>a[y.x][y.y];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            for(int j=1;j<=m;j++)
            {
                a[i][j]=s[j]-'0';
            }
        }
        nn=0;
        for(int i=1;i<n;i++)for(int j=1;j<m;j++)solve(i,j);
        for(int i=1;i<n-1;i++)solve2(i,m-1);
        p[0].x=n-1;p[0].y=m-1;
        p[1].x=n-1;p[1].y=m;
        p[2].x=n;p[2].y=m-1;
        p[3].x=n;p[3].y=m;
        sort(p,p+4,cmp);
        switch(a[n-1][m-1]+a[n][m]+a[n][m-1]+a[n-1][m])
        {
            case 0:break;
            case 1:solve31(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);break;
            case 2:solve32(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);break;
            case 3:solve33(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);break;
        }
        cout<<nn<<endl;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]){while(1){if(i+1>=n)return 1;};}
        for(int i=0;i<nn;i++)
        {
            for(int j=0;j<6;j++)
                printf("%d%c",ans[i][j],' ');
            putchar(10);
        }

    }
    return 0;
}
/*
5
2 2
10
11

2 3
011
101

3 2
10
01
10

2 2
01
11

2 2
10
11

2 2
11
10
//////////////////////////
500

3 3
111
101
101

4 3
111
101
110
111

4 4
1111
1011
1111
1110

4 4
0000
0000
0000
0000

4 4
1000
0000
0000
0000
*/