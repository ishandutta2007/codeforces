#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long sum=0;
        long long x=0;
        for(int i=0;i<n;i++)
        {
            long long d;
            scanf("%I64d",&d);
            sum+=d;
            x^=(2*d);
        }
        long long a=0,b=0,c=0;
        for(long long i=0;i<60;i++)
        {
            if(((sum>>i)%2)==((x>>i)%2)) continue;
            a+=(1ll<<i);
            sum+=(1ll<<i);
            x^=(1ll<<(i+1));
            if(((sum>>(i+1))%2)==0&&((x>>(i+1))%2)==1)
            {
                b+=(1ll<<i);
                c+=(1ll<<i);
                sum+=(1ll<<(i+1));
            }
        }
        //if(sum==x) cout << "OK" << endl;
        printf("3\n");
        printf("%I64d %I64d %I64d\n",a,b,c);
    }
    return 0;
}