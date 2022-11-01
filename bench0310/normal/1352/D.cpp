#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n,0);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        int l=0,r=n-1;
        int x=0;
        int a=0,b=0;
        int z=0;
        while(l<=r)
        {
            int now=0;
            while(l<=r&&now<=x)
            {
                if(!(z&1)) now+=v[l++];
                else now+=v[r--];
            }
            if(!(z&1)) a+=now;
            else b+=now;
            x=now;
            z++;
        }
        printf("%d %d %d\n",z,a,b);
    }
    return 0;
}