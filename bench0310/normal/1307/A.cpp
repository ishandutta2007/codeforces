#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        vector<int> v(n,0);
        for(int i=0;i<n;i++) scanf("%d",&v[i]);
        for(int o=1;o<n;o++)
        {
            while(v[o]>0&&o<=d)
            {
                v[0]++;
                v[o]--;
                d-=o;
            }
        }
        printf("%d\n",v[0]);
    }
    return 0;
}