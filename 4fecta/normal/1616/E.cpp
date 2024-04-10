#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

// A collection of sparse fenwick trees implemented in various methods
// Some are only sparse in 1 dimension, others are sparse in 2 dimensions
// Certain implementations only allow for increments and decrements of 1
// In general, offline fenwick trees are faster than sqrt implementations,
//   which are faster than the pbds implementations

// Sparse Fenwick Tree supporting point updates (with any value)
//   and range queries over a cumulative function or functor,
//   such as sum, max, and min, in 2 dimensions (sparse in 1 dimension)
// All update indices must be known beforehand
// Indices are 0-indexed and ranges are inclusive
// Template Arguments:
//   T: the type of each element
//   IndexType: the type of the index of the second dimension of the array
//   Op: a struct with the cumulative operation (plus<T> by default)
//     Required Functions:
//       operator (l, r): combines the values l and r, must be associative and
//         commutatitve
// Constructor Arguments:
//   N: the size of the first dimension of the array
//   updateInds: a vector of pairs of ints and IndexType containing the indices
//     for both dimensions for each update
//   qdef: the identity element of the operation
//   op: an instance of the Op struct
// Functions:
//   update(i, j, v): modifies the value A[i][j] to op(A[i][j], v), (i, j)
//     must be an element of updateInds
//   query(d, r): queries the cumulative value of the range [0, d] in the
//     first dimension and [0, r] in the second dimension
//   query(d, l, r, inv): queries the cumulative value of the range [0, d]
//     in the first dimension and [l, r] in the second dimension, where inv is
//     the inverse of op (minus<T>() by default)
//   query(u, d, l, r, inv): queries the cumulative value of the range [u, d]
//     in the first dimension and [l, r] in the second dimension, where inv is
//     the inverse of op (minus<T>() by default)
// In practice, has a small constant
// Time Complexity:
//   constructor: O(Q (log Q + log N) + N) for U updates
//   update, query: O(log N log U) for U updates
// Memory Complexity: O(N + U log N) for U updates
// Tested:
//   https://codeforces.com/contest/1093/problem/E
//   https://codeforces.com/contest/1523/problem/G
template <class T, class IndexType = int, class Op = plus<T>>
        struct OfflineSemiSparseFenwickTree2D {
            static_assert(is_integral<IndexType>::value, "IndexType must be integeral");
            int N; vector<int> st, cnt; vector<IndexType> inds; vector<T> BIT;
            T qdef; Op op;
            int getInd(int i, IndexType j) {
                return upper_bound(inds.begin() + st[i], inds.begin() + st[i] + cnt[i], j)
                - inds.begin() - st[i];
            }
            OfflineSemiSparseFenwickTree2D(int N,
                                           vector<pair<int, IndexType>> updateInds,
                                           T qdef = T(), Op op = Op())
                                           : N(N), st(N + 1, 0), cnt(N + 1, 0), qdef(qdef), op(op) {
                sort(updateInds.begin(), updateInds.end(),
                     [&] (const pair<int, IndexType> &a, const pair<int, IndexType> &b) {
                    return a.second < b.second;
                });
                vector<IndexType> last(N + 1, IndexType());
                for (auto &&u : updateInds) for (int i = u.first + 1; i <= N; i += i & -i)
                    if (cnt[i] == 0 || u.second != last[i]) { cnt[i]++; last[i] = u.second; }
                for (int i = 1; i <= N; i++) st[i] = st[i - 1] + cnt[i - 1];
                inds.resize(st[N] + cnt[N]); BIT.resize(st[N] + cnt[N], qdef);
                fill(cnt.begin(), cnt.end(), 0); for (auto &&u : updateInds)
                    for (int i = u.first + 1; i <= N; i += i & -i)
                        if (cnt[i] == 0 || u.second != inds[st[i] + cnt[i] - 1])
                            inds[st[i] + cnt[i]++] = u.second;
            }
            void update(int i, IndexType j, T v) {
                for (i++; i <= N; i += i & -i)
                    for (int s = st[i], c = cnt[i], y = getInd(i, j); y <= c; y += y & -y)
                        BIT[s + y - 1] = op(BIT[s + y - 1], v);
            }
            T query(int d, IndexType r) {
                T ret = qdef; for (d++; d > 0; d -= d & -d)
                    for (int s = st[d], y = getInd(d, r); y > 0; y -= y & -y)
                        ret = op(ret, BIT[s + y - 1]);
                    return ret;
            }
            template <class Inv = minus<T>>
                    T query(int d, IndexType l, IndexType r, Inv inv = Inv()) {
                return inv(query(d, r), query(d, l - 1));
            }
            template <class Inv = minus<T>>
                    T query(int u, int d, IndexType l, IndexType r, Inv inv = Inv()) {
                return inv(query(d, l, r), query(u - 1, l, r));
            }
        };

const int MN = 100005;

int q, n, s[MN], t[MN];
char c;
queue<int> pos[26];

/*void upd(int x, int val) {
    for (int i = x; i < MN; i += i & -i) bit[i] += val;
}

int qry(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}*/

int32_t main() {
    boost();

    cin >> q;
    while (q--) {

        cin >> n;
        vector<pii> upds;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            s[i] = c - 'a';
            pos[s[i]].push(i);
            upds.push_back({i, n + 1});
        }
        for (int i = 1; i <= n; i++) {
            cin >> c;
            t[i] = c - 'a';
        }

        for (int i = 1; i <= n; i++) {
            int id = 0x3f3f3f3f;
            for (int j = 0; j < t[i]; j++) {
                if (pos[j].size()) id = min(id, pos[j].front());
            }
            if (id <= n) upds.push_back({id, i});
            if (pos[t[i]].empty()) break;
            id = pos[t[i]].front(); pos[t[i]].pop();
            upds.push_back({id, i});
        }
        OfflineSemiSparseFenwickTree2D<int> bit(n + 1, upds);

        for (int i = 0; i < 26; i++) {
            while (pos[i].size()) pos[i].pop();
        }
        for (int i = 1; i <= n; i++) {
            bit.update(i, n + 1, 1);
            pos[s[i]].push(i);
        }

        int ans = LLONG_MAX, invs = 0;
        for (int i = 1; i <= n; i++) {
            int id = 0x3f3f3f3f;
            for (int j = 0; j < t[i]; j++) {
                if (pos[j].size()) id = min(id, pos[j].front());
            }
            if (id <= n) {
                //printf("%lld\n", id);
                bit.update(id, n + 1, -1);
                bit.update(id, i, 1);
                invs += bit.query(id - 1, i + 1, n + 1);
                ans = min(ans, invs);
                invs -= bit.query(id - 1, i + 1, n + 1);
                bit.update(id, i, -1);
                bit.update(id, n + 1, 1);
            }
            if (pos[t[i]].empty()) break;
            id = pos[t[i]].front(); pos[t[i]].pop();
            bit.update(id, n + 1, -1);
            bit.update(id, i, 1);
            invs += bit.query(id - 1, i + 1, n + 1);
        }
        printf("%lld\n", ans == LLONG_MAX ? -1 : ans);

        for (int i = 0; i < 26; i++) {
            while (pos[i].size()) pos[i].pop();
        }
    }

    return 0;
}