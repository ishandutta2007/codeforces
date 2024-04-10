#include"bits/stdc++.h"
using namespace std;
int num[200005];
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            num[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            num[a[i]]++;
        }
        int ok=0;
        for(;;ok++)
        {
            if(ok-(n-ok)>=k)break;
        }
        int bestl=0,bestr=1e9;
        int now=num[1];
        for(int l=1,r=1;;)
        {
            if(now<ok)
            {
                if(r==n)break;
                r++;
                now+=num[r];
                continue;
            }
            if(bestr-bestl>r-l)
            {
                bestr=r;
                bestl=l;
            }
            now-=num[l];
            l++;
        }
        cout<<bestl<<" "<<bestr<<endl;
        int l=1;
        while(k>1)
        {
            now=0;
            for(int i=l;;)
            {
                if(bestl<=a[i]&&a[i]<=bestr)now++;
                else now--;
                if(now==1)
                {
                    printf("%d %d\n",l,i);
                    l=i+1;
                    break;
                }
                i++;
            }
            k--;
        }
        cout<<l<<" "<<n<<endl;
    }
    return 0;
}