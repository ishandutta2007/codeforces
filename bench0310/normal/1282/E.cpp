#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<int> q;
map<tuple<int,int,int>,int> m;
map<pair<int,int>,set<int>> three;

void rem(int a,int b,int c)
{
    vector<int> v={a,b,c};
    sort(v.begin(),v.end());
    do
    {
        three[{v[0],v[1]}].erase(v[2]);
    } while(next_permutation(v.begin(),v.end()));
}

void solve(int a,int b)
{
    p.push_back(a);
    if(!three[{a,b}].empty())
    {
        int c=*three[{a,b}].begin();
        rem(a,b,c);
        solve(a,c);
        p.push_back(c);
        solve(c,b);
        q.push_back(m[make_tuple(a,b,c)]);

    }
    p.push_back(b);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<vector<int>> v(n,vector<int>(3));
        vector<int> cnt(n+1,0);
        for(int o=0;o<n-2;o++)
        {
            for(int i=0;i<3;i++) scanf("%d",&v[o][i]);
            for(int i=0;i<3;i++) cnt[v[o][i]]++;
            sort(v[o].begin(),v[o].end());
            do
            {
                three[{v[o][0],v[o][1]}].insert(v[o][2]);
                m[make_tuple(v[o][0],v[o][1],v[o][2])]=o+1;
            } while(next_permutation(v[o].begin(),v[o].end()));
        }
        int one=0;
        for(int i=1;i<=n;i++) if(cnt[i]==1) one=i;
        int two=0;
        for(int i=1;i<=n;i++)
        {
            if(i==one) continue;
            if(!three[{one,i}].empty()) two=i;
        }
        solve(one,two);
        while(p.back()==p[0]) p.pop_back();
        int num=0;
        for(int i=0;num<n;i++)
        {
            if(i>0&&p[i]==p[i-1]) continue;
            printf("%d ",p[i]);
            num++;
        }
        printf("\n");
        for(int i=0;i<n-2;i++) printf("%d ",q[i]);
        printf("\n");
        m.clear();
        p.clear();
        q.clear();
    }
    return 0;
}