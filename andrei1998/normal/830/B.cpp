#include <iostream>

using namespace std;

const int NMAX = 1E5 + 15;
struct Node {
    int st, dr;
    int minimum;
} tree[4 * NMAX];

int a[NMAX];
void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;
    if (st == dr) {
        tree[node].minimum = a[st];
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    build(node << 1, st, mid);
    build((node << 1) + 1, mid + 1, dr);
    tree[node].minimum = min(tree[node << 1].minimum, tree[(node << 1) + 1].minimum);
}

int getMin(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].minimum;

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        return getMin(node << 1, st, dr);
    else if (st > mid)
        return getMin((node << 1) + 1, st, dr);
    else
        return min(getMin(node < 1, st, mid),
                   getMin((node << 1) + 1, mid + 1, dr));
}

void update(int node, int val, int where) {
    if (tree[node].st == tree[node].dr) {
        tree[node].minimum = val;
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (where <= mid)
        update(node << 1, val, where);
    else
        update((node << 1) + 1, val, where);
    tree[node].minimum = min(tree[node << 1].minimum, tree[(node << 1) + 1].minimum);
}

inline int lsb(int node) {
    return node & (-node);
}

int N;
int aib[NMAX];

void updAib(int where) {
    for (; where <= N; where += lsb(where))
        aib[where] --;
}

int queryAib(int where) {
    int ans = 0;
    for (; where; where -= lsb(where))
        ans += aib[where];
    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> N;

    for (int i = 1; i <= N; ++ i)
        cin >> a[i];
    build(1, 1, N);

    for (int i = 1; i <= N; ++ i)
        aib[i] = lsb(i);

    long long int ans = 0;
    int where = 1;
    while (1) {
        int minimum = getMin(1, 1, N);
        if (minimum > NMAX)
            break;

        if (getMin(1, where, N) == minimum) {
            int st = where;
            int dr = N - 1;
            int res = N;

            while (st <= dr) {
                int mid = (st + dr) >> 1;
                if (getMin(1, st, mid) == minimum) {
                    res = mid;
                    dr = mid - 1;
                }
                else
                    st = mid + 1;
            }

            ans += queryAib(res) - queryAib(where - 1);
            update(1, NMAX + 15, res);
            updAib(res);
            where = res % N + 1;
        }
        else {
            ans += queryAib(N) - queryAib(where - 1);
            where = 1;
        }
    }

    cout << ans << '\n';
    return 0;
}