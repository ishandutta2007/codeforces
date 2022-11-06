#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 3e5 + 9;
const int B = 19;

int n, Q;
int a[MxN + 9];
vector<int> path[MxN + 9];

void merge(vector<int> &v1, vector<int> &v2) {
    vector<int> res;

    auto it1 = v1.begin(), it2 = v2.begin();
    int mask = 0;

    while (it1 != v1.end() || it2 != v2.end()) {
        vector<int>::iterator &it = it2 == v2.end() || (it1 != v1.end() && *it1 < *it2) ? it1 : it2;

        const int mask2 = mask | a[*it];
        if (mask2 != mask) {
            mask = mask2;
            res.push_back(*it);
        }
        ++it;
    }

    v1 = move(res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> Q;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    array<int, B> nxt;
    nxt.fill(n + 1);

    for (int i = n; i >= 1; --i) {
        path[i] = {i};
        for (int j = 0; j < B; ++j)
            if (a[i] & (1 << j)) {
                const int k = nxt[j];
                assert(k > i);
                merge(path[i], path[k]);
                nxt[j] = i;
            }
        path[i].shrink_to_fit();
    }

    while (Q--) {
        int I, J;
        cin >> I >> J;


        bool yes = false;

        for (const int i : path[I]) {
            if (i > J)
                break;
            yes = a[i] & a[J];
            if (yes)
                break;
        }
        cout << (yes ? "Shi" : "Fou") << '\n';
    }
    return 0;
}