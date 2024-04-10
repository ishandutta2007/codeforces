#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 200005;

struct Query {
    int first, second, pos;
    bool operator <(const Query& other) const {
        return first < other.first;
    }
};

pair<int, int> A[Nmax];
Query Q[Nmax];

int Aint[5 * Nmax], Lazy[5 * Nmax];
int Ans[Nmax];

void Split(int node, int left, int right) {
    if (Lazy[node]) {
        Lazy[node] = 0;
        Aint[node] = 0;

        if (left < right - 1)
            Lazy[2 * node] = Lazy[2 * node + 1] = 1;
    }
}

void Lupdate(int node, int left, int right, int lq, int rq) {
    Split(node, left, right);
    if (lq <= left && right <= rq) {
        Lazy[node] = 1;
        Aint[node] = 0;
        return;
    }

    int mid = (left + right) / 2;
    if (lq < mid) Lupdate(2 * node, left, mid, lq, rq);
    if (rq > mid) Lupdate(2 * node + 1, mid, right, lq, rq);

    Split(2 * node, left, mid);
    Split(2 * node + 1, mid, right);
    Aint[node] = Aint[2 * node] + Aint[2 * node + 1];
}

void Build(int node, int left, int right) {
    if (left < right - 1) {
        int mid = (left + right) / 2;
        Build(2 * node, left, mid);
        Build(2 * node + 1, mid, right);
    }

    Aint[node] = A[right].first - A[left].first;
}

void Update(int node, int left, int right, int lq, int rq, int val) {
    Split(node, left, right);
    if (lq <= left && right <= rq) {
        Aint[node] = min(Aint[node], A[right].first - A[left].first - val);
        return;
    }

    int mid = (left + right) / 2;
    if (lq < mid) Update(2 * node, left, mid, lq, rq, val);
    if (rq > mid) Update(2 * node + 1, mid, right, lq, rq, val);

    Split(2 * node, left, mid);
    Split(2 * node + 1, mid, right);
    Aint[node] = Aint[2 * node] + Aint[2 * node + 1];
}

int Query(int node, int left, int right, int lq, int rq) {
    Split(node, left, right);
    if (lq <= left && right <= rq)
        return Aint[node];

    int mid = (left + right) / 2, ret = 0;
    if (lq < mid) ret += Query(2 * node, left, mid, lq, rq);
    if (rq > mid) ret += Query(2 * node + 1, mid, right, lq, rq);
    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE


    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &A[i].first, &A[i].second);

    Build(1, 1, N);

    int M;
    scanf("%d", &M);

    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &Q[i].first, &Q[i].second);
        Q[i].pos = i;
    }

    sort(Q + 1, Q + M + 1);

    for (int i = M, j = N; i > 0; --i) {
        while (j > 0 && j >= Q[i].first) {
            if (j != N) {
                int pos = j;
                for (int step = (1 << 18); step > 0; step >>= 1)
                    if (pos + step <= N && A[pos + step].first <= A[j].first + A[j].second)
                        pos += step;

                if (pos > j) Lupdate(1, 1, N, j, pos);
                if (A[j].first + A[j].second > A[pos].first && pos < N)
                    Update(1, 1, N, pos, pos + 1, A[j].first + A[j].second - A[pos].first);
            }
            --j;
        }

        Ans[Q[i].pos] = Query(1, 1, N, Q[i].first, Q[i].second);
    }

    for (int i = 1; i <= M; ++i)
        printf("%d\n", Ans[i]);

    puts("");
}