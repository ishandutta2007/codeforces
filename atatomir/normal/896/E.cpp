#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;
const int no_value = maxN - 2;
const int bucket_size = 500;
const int bucket_cnt = maxN / bucket_size + 5;

int n, m, i, l, r, x, tp, buckets;
int v[maxN];
int dad[maxN], pos[maxN], down[maxN];
vector<int> data[bucket_cnt];
int delta[bucket_cnt];



int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

void prepare(int id) {
    int i;
    int maxi = 0;
    int l = id * bucket_size;
    int r = min(n - 1, (id + 1) * bucket_size - 1);

    for (i = l; i <= r; i++) maxi = max(maxi, v[i]), dad[i] = i;

    if (data[id].empty())
        data[id] = vector<int>(maxi + 1, no_value);

    for (i = l; i <= r; i++) {
        if (data[id][delta[id] + v[i]] == no_value) {
            data[id][delta[id] + v[i]] = i;
            pos[i] = delta[id] + v[i];
            down[i] = 1;
        } else {
            dad[i] = data[id][delta[id] + v[i]];
            down[data[id][delta[id] + v[i]]]++;
        }
    }
}

void refresh(int id) {
    int l = id * bucket_size;
    int r = min(n - 1, (id + 1) * bucket_size - 1);

    for (int i = l; i <= r; i++) {
        data[id][pos[Find(i)]] = no_value;
        v[i] = pos[Find(i)] - delta[id];
    }

}

void update_bucket(int id) {
    int p1, p2, sz, i;
    int* aux;

    p1 = x + 1;
    p2 = data[id].size() - p1 - delta[id];
    if (p2 <= 0) return;

    aux = data[id].data();
    aux += delta[id];
    sz = data[id].size() - delta[id];

    if (x >= p2) {
        for (i = x + 1; i < sz; i++) {
            int n1 = aux[i - x];
            int n2 = aux[i];

            if (n2 == no_value) continue;
            if (n1 == no_value) {
                aux[i - x] = n2;
                pos[n2] = i - x + delta[id];
            } else {
                dad[n2] = n1;
                down[n1] += down[n2];
            }

            aux[i] = no_value;
        }

        data[id].resize(delta[id] + x + 1);
    } else {
        for (i = 1; i <= x; i++) {
            int n1 = aux[i + x];
            int n2 = aux[i];

            if (n2 == no_value) continue;
            if (n1 == no_value) {
                aux[i + x] = n2;
                pos[n2] = i + x + delta[id];
            } else {
                dad[n2] = n1;
                down[n1] += down[n2];
            }

            aux[i] = no_value;
        }

        delta[id] += x;
    }

    if (data[id].size() > 1)
        while (data[id].size() > 1 && data[id].back() == 0)
            data[id].pop_back();

}

void update() {
    int i;
    int b1, b2;

    b1 = l / bucket_size;
    b2 = r / bucket_size;
    refresh(b1);
    if (b1 != b2) refresh(b2);

    int limit = min(bucket_size * (b1 + 1) - 1, r);
    for (i = l; i <= limit; i++)
        if (v[i] > x)
            v[i] -= x;

    if (b1 != b2) {
        limit = bucket_size * b2;
        for (i = r; i >= limit; i--)
            if (v[i] > x)
                v[i] -= x;
    }

    prepare(b1);
    if (b1 != b2) prepare(b2);

    for (i = b1 + 1; i < b2; i++)
        update_bucket(i);

}

int query() {
    int i;
    int b1, b2;
    int ans = 0;

    b1 = l / bucket_size;
    b2 = r / bucket_size;

    int limit = min(bucket_size * (b1 + 1) - 1, r);
    for (i = l; i <= limit; i++)
        ans += ( (pos[Find(i)] - delta[b1])  == x);

    if (b1 != b2) {
        limit = bucket_size * b2;
        for (i = r; i >= limit; i--)
            ans += ( (pos[Find(i)] - delta[b2]) == x);
    }


    for (i = b1 + 1; i < b2; i++) {
        if (x > data[i].size() - 1 - delta[i]) continue;
        ans += down[data[i][x + delta[i]]];
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &v[i]);

    buckets = (n - 1) / bucket_size;
    for (i = 0; i < n; i += bucket_size)
        prepare(i / bucket_size);

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &tp, &l, &r, &x);
        l--; r--;

        if (tp == 1)
            update();
        else
            printf("%d\n", query());
    }

    return 0;
}