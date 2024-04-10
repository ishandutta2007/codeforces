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
        set<int> s;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            s.insert(a&1);
        }
        if(s.size()==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}