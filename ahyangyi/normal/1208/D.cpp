#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200000;
long long tree[200000 * 2 - 1];

int make_tree(int l, int r)
{
    if (l == r)
    {
        tree[l + r] = l + 1;
        return l + r;
    }

    int pos = ((l + r) | (l != r));
    int pl = make_tree(l, (l + r) / 2);
    int pr = make_tree((l + r) / 2 + 1, r);
    tree[pos] = tree[pl] + tree[pr];

    return pos;
}

int find_and_erase(int l, int r, long long sum)
{
    if (l == r)
    {
        tree[l + r] = 0;
        return l;
    }

    int pos = ((l + r) | (l != r));
    int lr = (l + r) / 2;
    int rl = lr + 1;
    int pl = ((l + lr) | (l != lr));
    int pr = ((rl + r) | (rl != r));

    if (sum < tree[pl])
    {
        int ans = find_and_erase(l, lr, sum);
        tree[pos] = tree[pl] + tree[pr];
        return ans;
    }
    else
    {
        int ans = find_and_erase(rl, r, sum - tree[pl]);
        tree[pos] = tree[pl] + tree[pr];
        return ans;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    make_tree(0, n - 1);

    vector<int> b(n);
    for (int i = n - 1; i >= 0; --i)
    {
        b[i] = find_and_erase(0, n - 1, a[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << b[i] + 1;
        if (i + 1 < n)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}