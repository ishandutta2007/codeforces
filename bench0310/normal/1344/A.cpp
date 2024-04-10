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
        vector<bool> v(n,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            a=((a%n)+n)%n;
            if(i+a>=n) a-=n;
            v[i+a]=1;
        }
        bool ok=1;
        for(int i=0;i<n;i++) if(v[i]==0) ok=0;
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}