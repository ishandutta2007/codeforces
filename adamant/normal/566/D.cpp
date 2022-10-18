#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000007;
map<int, int> me;
vector<int> st[maxn];

int merg(int a, int b)
{
    auto it1 = --me.upper_bound(a);
    auto it2 = --me.upper_bound(b);
    a = it1->second;
    b = it2->second;
    if(a == b)
        return b;
    if(st[a].size() > st[b].size())
        swap(a, b);
    for(auto it: st[a])
        if(me.count(it))
            me[it] = b;
    for(auto it: st[a])
    {
        auto IT = --me.upper_bound(it);
        if(IT->first != it)
            continue;
        st[b].push_back(it);
        auto IT2 = IT;
        IT2++;
        while(IT2->second == IT->second)
            IT2 = me.erase(IT2);
        IT2 = IT;
        IT2--;
        if(IT2->second == IT->second)
            me.erase(IT);
    }
    return b;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= n + 1; i++)
        me[i] = i;
    for(int i = 0; i <= n + 1; i++)
        st[i].push_back(i);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int a, b;
            cin >> a >> b;
            merg(a, b);
        }
        if(t == 2)
        {
            int a, b;
            cin >> a >> b;
            vector<int> que;
            auto it = --me.upper_bound(a);
            while(it->first <= b)
                que.push_back((it++)->second);
            b = que[0];
            for(int i = 1; i < que.size(); i++)
                b = merg(b, que[i]);
        }
        if(t == 3)
        {
            int a, b;
            cin >> a >> b;
            auto it1 = --me.upper_bound(a);
            auto it2 = --me.upper_bound(b);
            if(it1->second == it2->second)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}