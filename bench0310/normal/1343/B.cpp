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
        if((n/2)&1) printf("NO\n");
        else
        {
            printf("YES\n");
            vector<int> a,b;
            int x=2;
            for(int i=0;i<n;i+=4)
            {
                a.push_back(x);
                a.push_back(x+2);
                b.push_back(x-1);
                b.push_back(x+3);
                x+=6;
            }
            for(int y:a) printf("%d ",y);
            for(int y:b) printf("%d ",y);
            printf("\n");
        }
    }
    return 0;
}