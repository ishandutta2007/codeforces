#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int INF = 1e9;

int dp[205][205][3][3];
tuple<int, int, int, int> nxt[205][205][3][3];

bool ckmax(int &a, int b) {
    return b > a ? a = b, true : false;
}

int solve(int a, int b, int winsA, int winsB) {
    if (winsA == 3 || winsB == 3)
        return a == 0 && b == 0 ? 0 : -INF;
    if (dp[a][b][winsA][winsB] != INF)
        return dp[a][b][winsA][winsB];

    dp[a][b][winsA][winsB] = -INF;
    int i = winsA + winsB, cap = i == 4 ? 15 : 25;
    assert(i < 5);

    // A wins CAP - (<= CAP - 2)
    if (a >= cap) {
        for (int x=0; x<=min(cap-2, b); x++)
            if (ckmax(dp[a][b][winsA][winsB], 1 + solve(a - cap, b - x, winsA + 1, winsB)))
                nxt[a][b][winsA][winsB] = {a - cap, b - x, winsA + 1, winsB};
    }
    // A wins by two, over CAP
    for (int x=cap+1; x<=a && x-2<=b; x++)
        if (ckmax(dp[a][b][winsA][winsB], 1 + solve(a - x, b - x + 2, winsA + 1, winsB)))
            nxt[a][b][winsA][winsB] = {a - x, b - x + 2, winsA + 1, winsB};

    // cases with B is analogous
    if (b >= cap) {
        for (int x=0; x<=min(cap-2, a); x++)
            if (ckmax(dp[a][b][winsA][winsB], -1 + solve(a - x, b - cap, winsA, winsB + 1)))
                nxt[a][b][winsA][winsB] = {a - x, b - cap, winsA, winsB + 1};
    }
    for (int x=cap+1; x<=b && x-2<=a; x++)
        if (ckmax(dp[a][b][winsA][winsB], -1 + solve(a - x + 2, b - x, winsA, winsB + 1)))
            nxt[a][b][winsA][winsB] = {a - x + 2, b - x, winsA, winsB + 1};

    return dp[a][b][winsA][winsB];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int a=0; a<=200; a++)
        for (int b=0; b<=200; b++)
            for (int winsA=0; winsA<3; winsA++)
                for (int winsB=0; winsB<3; winsB++)
                    dp[a][b][winsA][winsB] = INF;

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        int ret = solve(a, b, 0, 0);
        if (ret < -3) {
            cout << "Impossible\n";
            continue;
        }
        assert(ret != 0);
        if (ret < 0)
            cout << 3 + ret << ":3\n";
        else
            cout << "3:" << 3 - ret << "\n";
        int winsA = 0, winsB = 0;
        for (int i=0; i<5; i++) {
            auto [na, nb, nwa, nwb] = nxt[a][b][winsA][winsB];
            cout << a - na << ":" << b - nb << " ";
            a = na;
            b = nb;
            winsA = nwa;
            winsB = nwb;
            if (winsA == 3 || winsB == 3)
                break;
        }
        cout << "\n";
    }

    return 0;
}