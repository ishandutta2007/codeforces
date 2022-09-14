#include <bits/stdc++.h>

using namespace std;

struct node
{
    struct node *l;
    struct node *r;
    int ll;
    int rr;
    int s;
    int pref;
    int suf;
};


struct node *build_tree(int l, int r)
{
    struct node *a;
    a = new(struct node);
    a->ll = l;
    a->rr = r;
    a->s = r - l;
    a->pref = r - l;
    a->suf = r - l;
    if (r - l > 1)
    {
        a->l = build_tree(l, (l + r) / 2);
        a->r = build_tree((l + r) / 2, r);
    }
    return a;
};


void update(struct node *a, int l)
{
    if (a->rr - a->ll == 1)
    {
        a->s = 0;
        a->pref = 0;
        a->suf = 0;
    }

    else
    {
        if (l < (a->ll + a->rr) / 2)
            update(a->l, l);
        else
            update(a->r, l);


        a->pref = a->l->pref;
        if (a->l->pref == a->l->rr - a->l->ll)
            a->pref += a->r->pref;

        a->suf = a->r->suf;
        if (a->r->pref == a->r->rr - a->r->ll)
            a->suf += a->l->suf;

        a->s = max(a->l->s, a->r->s);
        a->s = max(a->s, a->l->suf + a->r->pref);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int w, h, n;
    cin >> w >> h >> n;
    struct node *wtree = build_tree(0, w - 1);
    struct node *htree = build_tree(0, h - 1);
    for (int i = 0; i < n; i++)
    {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'H')
            update(htree, a - 1);
        else
            update(wtree, a - 1);
        long long ans;
        ans = (long long) (htree->s + 1) * (wtree->s + 1);
        cout << ans << endl;
    }
}