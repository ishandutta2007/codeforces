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
            int t;
            scanf("%d",&t);
            if(!(t&1)) s.insert(t);
        }
        int res=0;
        while(s.size())
        {
            int a=(*s.rbegin());
            s.erase(a);
            a/=2;
            res++;
            if(!(a&1)) s.insert(a);
        }
        printf("%d\n",res);
    }
    return 0;
}