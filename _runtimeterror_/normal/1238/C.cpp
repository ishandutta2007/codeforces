#include<iostream>
#include<vector>

using namespace std;

const int N=200005;
int h[N];

int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        int n,H;
        scanf("%d %d",&H,&n);
        for(int i=0;i<n;++i)
            scanf("%d",h+i);
        h[n]=0;
        
        int cur=H,ans=0;
        for(int i=1;i<=n;++i)
        {
            if(cur>h[i]+1)
            {
                cur=h[i]+1;
            }
            if(i!=n)
            {
                if(h[i+1]!=h[i]-1)
                    ++ans,cur=h[i]-1;
                else
                    cur=h[i-1],++i;
            }
        }

        printf("%d\n", ans);
    }
}