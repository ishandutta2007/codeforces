#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

const int n=500000;
const int sz=707;
int a[n+5];
int sq[sz+5][sz+5]; //src,step

int solve(int src,int step)
{
    int res=0;
    for(int i=src;i<=n;i+=step) res+=a[i];
    return res;
}

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        if(t==1)
        {
            a[x]+=y;
            for(int i=1;i<=sz;i++)
            {
                int k=((x-1)/i);
                sq[x-k*i][i]+=y;
            }
        }
        else
        {
            if(y==0) y=x;
            if(x<=sz) printf("%d\n",sq[y][x]);
            else printf("%d\n",solve(y,x));
        }
    }
 	return 0;
}