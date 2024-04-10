#include <bits/stdc++.h>

using namespace std;

int n;
char a[2][200005];

bool solve(int r,int c,bool l)
{
    if(r==1&&c==n) return 1;
    if(l)
    {
        if(a[r][c]<='2') return solve(r,c+1,1);
        else return solve(1-r,c,0);
    }
    else
    {
        if(a[r][c]<='2') return 0;
        else return solve(r,c+1,1);
    }
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        scanf("%s",a[0]);
        scanf("%s",a[1]);
        if(solve(0,0,1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}