#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

inline int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int T;
int freq[NMAX];
int N, M;

// For a fixed grid and center square check for a solution
int freq2[NMAX];
void doTry(int l, int c) {
    for (int i = 0; i < T; ++ i)
        freq2[i] = 0;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            ++ freq2[dist(l, c, i, j)];

    for (int i = 0; i < T; ++ i)
        if (freq[i] != freq2[i])
            return ;
    cout << N << ' ' << M << endl;
    cout << l << ' ' << c << endl;
    exit(0);
}

void check() {
    static int maxDist = []() {
        int last = 0;
        for (int i = 0; i < T; ++ i)
            if (freq[i])
                last = i;
        return last;
    }();

    static int distToNearestSide = []() {
        // 1, 4, 8, 12, ...
        if (freq[0] != 1)
            return 0;
        for (int i = 1; i < T; ++ i)
            if (freq[i] != 4 * i)
                return i;
        assert(false);
    }();

    auto getDistToCorner = [](int l, int c) {
        const int v1 = l - 1 + c - 1;
        const int v2 = N - l + c - 1;
        const int v3 = M - c + l - 1;
        const int v4 = M - c + N - l;
        return max({v1, v2, v3, v4});
    };
    auto getDistToSide = [](int l, int c) {
        const int v1 = l;
        const int v2 = c;
        const int v3 = N + 1 - l;
        const int v4 = M + 1 - c;
        return min({v1, v2, v3, v4});
    };

    for (int l = 1; l <= N; ++ l)
        for (int c = 1; c <= M; ++ c)
            if (getDistToCorner(l, c) == maxDist && getDistToSide(l, c) == distToNearestSide)
                doTry(l, c);
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; ++ i) {
        int val;
        cin >> val;
        ++ freq[val];
    }
    if (T == 1) {
        if (freq[0] == 1)
            cout << "1 1\n1 1\n";
        else
            cout << "-1\n";
        return 0;
    }
    for (int div = 1; 1LL * div * div <= T; ++ div)
        if (T % div == 0) {
            N = div;
            M = T / div;
            check();
        }
    cout << "-1\n";
    return 0;
}