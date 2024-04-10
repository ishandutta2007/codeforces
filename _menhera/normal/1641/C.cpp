#include <bits/stdc++.h>
using namespace std;

struct Node
{
    const Node *l, *r;
    bool ch;
    int cn;
    Node(const Node *l, const Node *r, bool ch, int cn) : l(l), r(r), ch(ch), cn(cn) {}
    const Node *setv(int f, int t, int s, int e) const
    {
        if (t < s || e < f || ch)
            return this;
        Node *ret = new Node(l, r, ch, cn);
        if (f <= s && e <= t)
        {
            ret->ch = 1;
            ret->cn = e - s + 1;
        }
        else
        {
            int m = (s + e) / 2;
            ret->l = ret->l->setv(f, t, s, m);
            ret->r = ret->r->setv(f, t, m + 1, e);
            ret->cn = ret->l->cn + ret->r->cn;
        }
        return ret;
    }
    int getv(int f, int t, int s, int e) const
    {
        // cout << f << " " << t << " " << s << " " << e << " " << l << " " << r << endl;
        if (t < s || e < f)
            return 0;
        if (f <= s && e <= t)
            return cn;
        int m = (s + e) / 2;
        if (ch)
            return min(e, t) - max(f, s) + 1;
        return l->getv(f, t, s, m) + r->getv(f, t, m + 1, e);
    }
};

const Node *build(int s, int e)
{
    if (s == e)
        return new Node(0, 0, 0, 0);
    int m = (s + e) / 2;
    return new Node(build(s, m), build(m + 1, e), 0, 0);
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int, int>> V(Q);
    const Node *r = build(1, N);
    vector<const Node *> n;
    for (auto &[a, b, c, d] : V)
    {
        cin >> a >> b;
        if (a == 0)
        {
            cin >> c >> d;
            if (!d)
                r = r->setv(b, c, 1, N);
        }
        n.push_back(r);
    }
    vector<vector<pair<int, int>>> onset(Q + 1);
    const Node *pos = build(1, N);
    for (int i = 0; i < Q; i++)
    {
        auto [a, b, c, d] = V[i];
        if (a == 0 && d == 1)
        {
            int lo = i - 1; // not onset
            int hi = Q;     // must onset
            while (lo + 1 != hi)
            {
                int mi = (lo + hi) / 2;
                if (n[mi]->getv(b, c, 1, N) == c - b)
                    hi = mi;
                else
                    lo = mi;
            }
            onset[hi].push_back({b, c});
        }
        for (auto [a, b] : onset[i])
            pos = pos->setv(a, b, 1, N);
        if (a == 1)
        {
            if (n[i]->getv(b, b, 1, N))
                cout << "NO\n";
            else if (pos->getv(b, b, 1, N))
                cout << "YES\n";
            else
                cout << "N/A\n";
        }
    }
}