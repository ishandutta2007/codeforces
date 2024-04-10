#include"bits/stdc++.h"
using namespace std;
int num[500];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        set<int>s;
        multiset<int>save;
        for(int i=1;i<=n;i++)s.insert(i);
        while(n--)
        {
            int k;
            scanf("%d",&k);
            if(s.find(k)==s.end())save.insert(k);
            else s.erase(k);
        }
        int ans=save.size();
        while(s.size())
        {
            if(*s.begin()*2>=*save.begin())
            {
                printf("-1\n");
                goto ne;
            }
            s.erase(s.begin());
            save.erase(save.begin());
        }
        printf("%d\n",ans);
        ne:;
    }
    return 0;
}