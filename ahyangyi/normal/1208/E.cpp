#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int MAXN = 1000000;
long long tree[MAXN * 2 - 1];

void add(int l, int r, int la, int ra, int v)
{
    if (l == la && r == ra)
    {
        int pos = ((l + r) | (l != r));
        tree[pos] += v;
        return;
    }

    int lr = (l + r) / 2;
    int rl = (l + r) / 2 + 1;
    if (la <= lr)
    {
        add(l, lr, la, std::min(lr, ra), v);
    }
    if (ra >= rl)
    {
        add(rl, r, std::max(rl, la), ra, v);
    }
}

void output(int l, int r, long long sum)
{
    if (l == r)
    {
        cout << sum + tree[l + r] << " ";
        return;
    }

    int pos = ((l + r) | (l != r));
    int lr = (l + r) / 2;
    int rl = (l + r) / 2 + 1;
    output(l, lr, sum + tree[pos]);
    output(rl, r, sum + tree[pos]);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    memset(tree, 0, sizeof(tree[0]) * (w * 2 - 1));
    deque<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        int l;
        cin >> l;

        int window_size = w - l + 1;

        q.clear();
        q.push_back(make_pair(-1, 0));
        for (int j = 0; j < w;)
        {
            while (!q.empty() && q.front().first + window_size <= j)
            {
                q.pop_front();
            }

            if (j <= l)
            {
                int x;
                if (j < l)
                {
                    cin >> x;
                }
                else
                {
                    x = 0;
                }
                while (!q.empty() && q.back().second <= x)
                {
                    q.pop_back();
                }

                q.push_back(make_pair(j, x));
            }

            int next_j;
            if (j == l)
            {
                next_j = max(j + 1, window_size - 1);
            }
            else
            {
                next_j = j + 1;
            }

            int v = q.front().second;
            add(0, w - 1, j, next_j - 1, v);
            j = next_j;
        }
    }

    output(0, w - 1, 0);
    cout << endl;

    return 0;
}