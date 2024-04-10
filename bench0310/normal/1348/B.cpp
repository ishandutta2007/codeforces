#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        vector<int> v(n,0);
        set<int> s;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
            s.insert(v[i]);
        }
        int cnt=s.size();
        if(cnt>k)
        {
            printf("-1\n");
            continue;
        }
        vector<int> res;
        for(int x:s) res.push_back(x);
        while((int)res.size()<k) res.push_back(res.back());
        int sz=res.size();
        printf("%d\n",sz*n);
        for(int o=0;o<n;o++) for(int x:res) printf("%d ",x);
        printf("\n");
    }
    return 0;
}