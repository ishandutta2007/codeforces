//program 516B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<bitset>
#include<ctime>

using namespace std;

int get()
{
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}

void output(int x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

const int maxn=2000;
const int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int n,m;
int deg[maxn][maxn];
char ans[maxn][maxn];
int sx[maxn*maxn],sy[maxn*maxn];

bool valid(int x,int y)
{
  return x>=0&&y>=0&&x<n&&y<m&&ans[x][y]=='.';
}

void paint(int x0,int y0,int x1,int y1)
{
  if(x0>x1)
    swap(x0,x1);
  if(y0>y1)
    swap(y0,y1);
  if(x0==x1)
    {ans[x0][y0]='<';ans[x0][y1]='>';}
  else
    {ans[x0][y0]='^';ans[x1][y0]='v';}
}

int main()
{
  n=get();
  m=get();
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      {
        char c;
        while(c=getchar(),c!='*'&&c!='.');
        ans[i][j]=c;
      }
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(ans[i][j]=='.')
        for(int d=0;d<4;d++)
          {
            int u=i+dir[d][0],v=j+dir[d][1];
            if(valid(u,v))
              deg[i][j]++;
          }
  int top=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(deg[i][j]==1)
        {
          sx[top]=i;
          sy[top]=j;
          top++;
        }
  while(top--)
    {
      int x=sx[top],y=sy[top],u,v;
      if(deg[x][y]!=1)
        continue;
      for(int d=0;d<4;d++)
        {
          u=x+dir[d][0];
          v=y+dir[d][1];
          if(valid(u,v))
            break;
        }
      paint(x,y,u,v);
      deg[x][y]=deg[u][v]=0;
      for(int d=0;d<4;d++)
        {
          int u0=u+dir[d][0],v0=v+dir[d][1];
          if(valid(u0,v0)) {
            deg[u0][v0]--;
          if(deg[u0][v0]==1)
            {
              sx[top]=u0;
              sy[top]=v0;
              top++;
            }}
            
        }
    }
  bool bad=false;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(ans[i][j]=='.')
        bad=true;
  if(bad)
    {
      printf("Not unique\n");
      return 0;
    }
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        putchar(ans[i][j]);
      putchar('\n');
    }
  return 0;
}