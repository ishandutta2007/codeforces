#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define A 30
#define M 60500
#define mod 1000000007ll

int n, a[M], des;

void read() {
    cin >> n >> des;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

struct node {
    int c, to[2], s[A];
    node() {
        fill(s, s + A, 0);
        fill(to, to + 2, 0);
        c = 0;
    }
} t[M * A];

int size = 1;

void upd(int v, int x) {
    t[v].c++;
    for (int i = 0; i < A; ++i, x >>= 1) {
        t[v].s[i] += (x & 1);
    }
}

void fill() {
    for (int i = 0; i < n; ++i) {
        int st = 0;
        for (int j = A - 1; j >= 0; --j) {
            int to = (a[i] >> j) & 1;

            if (t[st].to[to] == 0) 
                t[st].to[to] = size++;

            

            st = t[st].to[to];

            upd(st, a[i]);
        }
    }
}

int subtreeSize(int v) {
    if (v == 0)
        return 0;
    return t[v].c;
}

int bigger(int val) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i] ^ val;
        int st = 0;
        for (int j = A - 1; j >= 0; --j) {
            int to = (x >> j) & 1;
            if (((val >> j) & 1) == 0)
                ans += subtreeSize(t[st].to[to ^ 1]);
            st = t[st].to[to];
            if (st == 0)
                break;
        }

        if (st != 0) 
            ans += subtreeSize(st);

    }

    if (val == 0)
        ans -= n; 

    return ans / 2;
}

void add(long long &ans, int x, int v) {
    if (v == 0)
        return;

    for (int j = 0; j < A; ++j) {
        long long c;
        if ((x >> j) & 1)
            c = t[v].c - t[v].s[j];
        else
            c = t[v].s[j];
        ans = ans + c * (1 << j);
    }
    ans %= mod;
}

int sum(int val) {
    long long ans = 0, c = bigger(val) - des;

    for (int i = 0; i < n; ++i) {
        int x = a[i] ^ val;
        int st = 0;
        for (int j = A - 1; j >= 0; --j) {
            int to = (x >> j) & 1;

            if (((val >> j) & 1) == 0) {
                add(ans, a[i], t[st].to[to ^ 1]);
            }

            st = t[st].to[to];
            if (st == 0)
                break;
        }


        if (st != 0) 
            add(ans, a[i], st);

    }

    ans = (ans * ((mod + 1) / 2)) % mod;

    ans = (ans - c * val) % mod;
    if (ans < 0)
        ans += mod;

    return ans;
}

void bin() {
    int l = 0, r = (1 << A) - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (bigger(m + 1) >= des)
            l = m + 1;
        else
            r = m;
    }

    cout << sum(l) << "\n";
}



int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    fill();
    bin();


    return 0;
}