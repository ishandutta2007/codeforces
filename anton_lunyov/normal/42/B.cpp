#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))

#define n 8
int a[n][n];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool check()
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==1 || a[i][j]==2)
            {
                for(k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];
                    for(;0<=x && x<n && 0<=y && y<n && a[x][y]==0;x+=dx[k],y+=dy[k]);
                    if(0<=x && x<n && 0<=y && y<n && a[x][y]==4) return true;
                }
            }
    return false;
}

int main()
{
   // freopen("b.in","r",stdin);
    char r1[5],r2[5],kw[5],kb[5];
    while(scanf("%s %s %s %s",r1,r2,kw,kb)>0)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        x1=r1[0]-'a';y1=r1[1]-'1';
        x2=r2[0]-'a';y2=r2[1]-'1';
        x3=kw[0]-'a';y3=kw[1]-'1';
        x4=kb[0]-'a';y4=kb[1]-'1';
        bool checkmate=true;
        int x,y;
        for(x=x4-1;x<=x4+1;x++)
            for(y=y4-1;y<=y4+1;y++)
            {
                if(0<=x && x<n && 0<=y && y<n)
                    if(abs(x-x3)>1 || abs(y-y3)>1)
                    {
                        fill(a,0);
                        a[x1][y1]=1;
                        a[x2][y2]=2;
                        a[x3][y3]=3;
                        a[x][y]=4;
                        if(!check()) checkmate=false;
                    }
            }
        puts(checkmate?"CHECKMATE":"OTHER");
    }
    return 0;
}