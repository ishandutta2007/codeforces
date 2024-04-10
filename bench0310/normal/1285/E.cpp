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
        vector<pair<int,int>> sg(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&sg[i].first,&sg[i].second);
            s.insert(sg[i].first);
            s.insert(sg[i].second);
        }
        int now=1;
        map<int,int> m;
        for(int a:s) m[a]=now++;
        vector<int> d(5*n,0);
        for(pair<int,int> &p:sg)
        {
            tie(p.first,p.second)=make_pair(2*m[p.first],2*m[p.second]);
            d[p.first]++;
            d[p.second+1]--;
        }
        vector<int> v(5*n,0);
        for(int i=1;i<5*n;i++) v[i]=v[i-1]+d[i];
        set<int> pos;
        for(int i=0;i<5*n;i++) if(v[i]>1) pos.insert(i);
        vector<int> dp(5*n,0);
        bool ok=0;
        for(int i=1;i<5*n-1;i++)
        {
            dp[i]=dp[i-1];
            if(v[i]==1&&v[i+1]>1&&ok) dp[i]++;
            if(v[i]==0) ok=0;
            if(v[i]>1) ok=1;
        }
        auto solve=[&](int l,int r)->int
        {
            if(l>r) return 0;
            if(v[l-1]==0&&v[r+1]==0) return -1;
            else if(v[l-1]==0||v[r+1]==0) return 0;
            else return 1;
        };
        int res=0;
        for(int i=0;i<5*n-1;i++) res+=(v[i]==0&&v[i+1]>0);
        int add=-n;
        for(pair<int,int> p:sg)
        {
            int l,r;
            tie(l,r)=p;
            if(pos.lower_bound(l)==pos.end()||(*pos.lower_bound(l)>r)) add=max(add,solve(l,r));
            else
            {
                int cnt=0;
                int a=(*pos.lower_bound(l));
                int b=(*prev(pos.upper_bound(r)));
                cnt+=solve(l,a-1);
                cnt+=solve(b+1,r);
                cnt+=(dp[b]-dp[a]);
                add=max(add,cnt);
            }
        }
        printf("%d\n",res+add);
    }
    return 0;
}