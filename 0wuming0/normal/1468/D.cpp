#include"bits/stdc++.h"
using namespace std;
int fr[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        int num=abs(a-b)-1;
        int time;
        if(a<b)time=a;
        else time=n-a+1;
        for(int i=0;i<m;i++)scanf("%d",fr+i);
        sort(fr,fr+m);
        int ans=0;
        for(int i=time,now=0;now<m&&i<time+num;)
        {
            if(fr[now]<=i)
            {
                ans++;
                i++;
                now++;
            }
            else if(fr[now]>=time+num)
            {
                break;
            }
            else
            {
                i=fr[now];
                ans++;
                i++;
                now++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}