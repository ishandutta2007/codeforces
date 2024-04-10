#include <bits/stdc++.h>

using namespace std;

const int MAX = (1 << 17) + 50;

int A[MAX], T[4 * MAX], n, q, p, v;

void Build (int node, int b, int e, int dist) {
    if (b == e) {
        T[node] = A[b];
        return;
    }

    int mid = (b + e) >> 1;
    int left = node + node;
    int right = left + 1;

    Build (left, b, mid, dist - 1);
    Build (right, mid + 1, e, dist - 1);

    if (dist & 1) T[node] = (T[left] | T[right]);
    else T[node] = (T[left] ^ T[right]);
}

void Update (int node, int b, int e, int pos, int val, int dist) {
    if (b > pos or e < pos) return;
    if (b == e and b == pos) {
        T[node] = val;
        return;
    }

    int mid = (b + e) >> 1;
    int left = 2 * node;
    int right = left + 1;

    Update (left, b, mid, pos, val, dist - 1);
    Update (right, mid + 1, e, pos, val, dist - 1);

    if (dist & 1) T[node] = (T[left] | T[right]);
    else T[node] = (T[left] ^ T[right]);
}

int Query (void) {
    return T[1];
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    int lim = (1 << n);
    for (int i = 1; i <= lim; i++) cin >> A[i];
    Build (1, 1, lim, n);

    while (q--) {
        cin >> p >> v;
        Update (1, 1, lim, p, v, n);
        cout << Query() << endl;
    }

    cout.flush();
    return 0;
}