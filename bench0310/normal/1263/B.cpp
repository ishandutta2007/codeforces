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
        vector<int> v(n);
        multiset<int> s;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
            s.insert(v[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(s.count(v[i])==1) continue;
            s.erase(s.find(v[i]));
            for(int j=0;j<=9;j++)
            {
                if(s.find(v[i]-(v[i]%10)+j)==s.end())
                {
                    v[i]=v[i]-(v[i]%10)+j;
                    break;
                }
            }
            s.insert(v[i]);
            res++;
        }
        printf("%d\n",res);
        for(int i=0;i<n;i++) printf("%04d\n",v[i]);
    }
    return 0;
}