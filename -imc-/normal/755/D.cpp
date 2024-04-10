#include <bits/stdc++.h>

using namespace std;

struct segtree
{
    vector<int> tree;
    int n;
    
    segtree(int n): tree(n * 4 + 100), n(n) {}
    
    void add(int t, int l, int r, int x, int y, int value)
    {
        if (l >= x && r <= y)
            return void(tree[t] += value);
        
        if (x > r || y < l)
            return;
        
        int m = (l + r) / 2;
        add(t * 2 + 1, l, m, x, y, value);
        add(t * 2 + 2, m + 1, r, x, y, value);
    }
    
    int query(int t, int l, int r, int index)
    {
        if (l == r)
            return tree[t];
        
        int m = (l + r) / 2;
        
        if (index <= m)
            return query(t * 2 + 1, l, m, index) + tree[t];
        else
            return query(t * 2 + 2, m + 1, r, index) + tree[t];
    }
    
    void add(int l, int r)
    {
        //printf("add %d..%d\n", l, r);
        if (l > r)
            return;
        add(0, 0, n - 1, l, r, 1);
    }
    
    int query(int i)
    {
        return query(0, 0, n - 1, i);
    }
    
    void add_cyclic(int l, int r)
    {
        l = (l % n + n) % n;
        r = (r % n + n) % n;
        
        if (l <= r)
            add(l, r);
        else
        {
            add(max(l,r), n - 1);
            add(0, min(l,r));
        }
    }
};

typedef long long li;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    if (k > n - k)
        k = n - k;
    
    // k > n - k !!
    
    segtree s(n);
    s.add(0, n - 1);
    
    li sectors = 1;
    
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        int next = (pos + k) % n;
        
        int add = s.query(pos);
        //printf("add %d index %d -> %lld\n", add, pos, sectors);
        sectors += add;
        
        s.add_cyclic(pos + 1, next - 1);
        s.add_cyclic(pos - k + 1, pos - 1);
        
        //for (int i = 0; i < n; i++)
            //printf("%d ", s.query(i));
        //printf("\n");
        
        pos = next;
        
        cout << sectors << ' ';
    }
    cout << endl;
    
    return 0;
}