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
        map<int,int> m;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            m[a[i]]++;
        }
        vector<int> b(n);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        bool ok=1;
        for(int i=n-1;i>=0;i--)
        {
            m[a[i]]--;
            if(a[i]<b[i]&&m[1]==0) ok=0;
            if(a[i]>b[i]&&m[-1]==0) ok=0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}