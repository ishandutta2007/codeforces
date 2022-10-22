#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct tree
{
    tree *left, *right;
    pair<li, li> add;
    
    tree(pair<li, li> add = make_pair(0, 0), tree* left = 0, tree* right = 0): left(left), right(right), add(add) {}
    
    tree* change(int l, int r, int x, int y, pair<li, li> by)
    {
        if (x > r || y < l) return this;
        
        if (l >= x && r <= y)
            return new tree(make_pair(add.first + by.first, add.second + by.second), left, right);
        
        int m = (l + r) / 2;
        return new tree(add, left->change(l, m, x, y, by), right->change(m + 1, r, x, y, by));
    }
    
    pair<li, li> query(int l, int r, int index)
    {
        if (l == r) return add;
        
        int m = (l + r) / 2;
        auto from = (index <= m ? left->query(l, m, index) : right->query(m + 1, r, index));
        from.first += add.first;
        from.second += add.second;
        return from;
    }
};

tree* build(int l, int r)
{
    if (l == r) return new tree;
    
    int m = (l + r) / 2;
    
    return new tree(make_pair(0LL, 0LL), build(l, m), build(m + 1, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const int maxN = 2 * 1e5 + 10;
    
    int n;
    cin >> n;
    
    vector<tree*> versions;
    tree* cur = build(0, maxN);
    versions.push_back(cur);
    
    for (int i = 0; i < n; i++)
    {
        int x1, x2;
        li a, b;
        li y1, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        
        cur = cur->change(0, maxN, 0, x1, make_pair(y1, (li)0));
        cur = cur->change(0, maxN, x1 + 1, x2, make_pair(b, a));
        cur = cur->change(0, maxN, x2 + 1, maxN, make_pair(y2, (li)0));
        
        versions.push_back(cur);
    }
    
    int nq;
    cin >> nq;
    
    li last = 0;
    for (int i = 0; i < nq; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        
        x = (last + x) % (int)1e9;
        
        int x_clamped = min(max(x, 0), maxN);
        auto p1 = versions[r]->query(0, maxN, x_clamped);
        auto p2 = versions[l - 1]->query(0, maxN, x_clamped);
        
        //printf("%lld %lld\n", p1.first, p1.second);
        
        p1.first -= p2.first;
        p1.second -= p2.second;
        
        last = p1.first + p1.second * x_clamped;
        assert(p1.first >= 0 && p1.second >= 0);
        
        cout << last << '\n';
    }
    
    return 0;
}