#include <iostream>
#include <deque>

using namespace std;

const int MAXN = 100 * 1000 + 5, BS = 350, BN = (MAXN + BS - 1) / BS;
int a[MAXN], c[BN][MAXN], l[MAXN], r[MAXN], x[MAXN], n;
deque<int> d[BN];

int getbl(int b, int q) {
    int bl = b * BS, br = min(bl + BS, n) - 1;
    if(bl >= l[q] && br <= r[q])
        return c[b][x[q]];
    int res = 0;
    for(int i = max(bl, l[q]); i <= min(br, r[q]); i++)
        if(d[b][i - bl] == x[q])
            res++;
    return res;
}

int get(int q) {
    int lb = l[q] / BS, rb = r[q] / BS, res = 0;
    for(int i = lb; i <= rb; i++)
        res += getbl(i, q);
    return res;
}

int rotbl(int b, int q, int p) {
    int bl = b * BS, br = min(bl + BS, n) - 1;
    if(bl >= l[q] && br <= r[q]) {
        d[b].push_front(p);
        c[b][p]++;
        int res = d[b].back();
        d[b].pop_back();
        c[b][res]--;
        return res;
    }
    int res = d[b][min(br, r[q]) - bl];
    c[b][res]--;
    for(int i = min(br, r[q]); i > max(bl, l[q]); i--)
        d[b][i - bl] = d[b][i - 1 - bl];
    d[b][max(0, l[q] - bl)] = p;
    c[b][p]++;
    return res;
}

void rot(int q) {
    int lb = l[q] / BS, rb = r[q] / BS, p = d[rb][r[q] - rb * BS];
    for(int i = lb; i <= rb; i++)
        p = rotbl(i, q, p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int qq;
        cin >> qq >> l[i] >> r[i];
        if(qq == 2)
            cin >> x[i];
    }
    int bn = (n + BS - 1) / BS;
    for(int i = 0; i < bn; i++) {
        for(int j = i * BS; j < (i + 1) * BS && j < n; j++) {
            d[i].push_back(a[j]);
            c[i][a[j]]++;
        }
    }
    int lastans = 0;
    for(int i = 0; i < q; i++) {
        l[i] = (l[i] + lastans - 1) % n;
        r[i] = (r[i] + lastans - 1) % n;
        if(l[i] > r[i])
            swap(l[i], r[i]);
        if(x[i]) {
            x[i] = (x[i] + lastans - 1) % n + 1;
            lastans = get(i);
            cout << lastans << '\n';
        }
        else
            rot(i);
    }
    return 0;
}