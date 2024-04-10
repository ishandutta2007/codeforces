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
        vector<int> p(n+1,0);
        vector<int> pos(n+1,0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            pos[p[i]]=i;
        }
        vector<int> cnt(n+1,1);
        multiset<int> s;
        for(int i=1;i<=n;i++) s.insert(cnt[i]);
        set<int> e;
        for(int i=0;i<=n+1;i++) e.insert(i);
        bool ok=1;
        auto ch=[&](int idx,int val)
        {
            s.erase(s.find(cnt[idx]));
            cnt[idx]=val;
            s.insert(cnt[idx]);
        };
        for(int i=1;i<=n;i++)
        {
            int now=pos[i];
            auto it=e.lower_bound(now);
            it--;
            int a=now-(*it)-1;
            it++;
            it++;
            int b=(*it);
            e.erase(now);
            if(cnt[now]<(*s.rbegin())) ok=0;
            ch(now,cnt[now]-a-1);
            if(b!=n+1) ch(b,cnt[b]+a+1);
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}