#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

vector<int> val[5555];

struct item {
    int t, x, y;
};

item kind[5555];
int n, m;

int calc(int j, int b) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (kind[i].t == -1) {
            continue;
        }
        int x = kind[i].x == -1 ? b : val[kind[i].x][j];
        int y = kind[i].y == -1 ? b : val[kind[i].y][j];
        if (kind[i].t == 1) {
            val[i][j] = x | y;
        } else if (kind[i].t == 2) {
            val[i][j] = x ^ y;
        } else if (kind[i].t == 3) {
            val[i][j] = x & y;
        } else {
            throw 1;
        }
        res += val[i][j];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, m);
    map<string, int> ids;
    ids["?"] = -1;
    for (int i = 0; i < n; i++) {
        val[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        scids(nm, tt, x);
        ids[nm] = i;
        if (x[0] != '1' && x[0] != '0') {
            scids(op, y);
            kind[i].x = ids[x];
            kind[i].y = ids[y];
            if (op == "OR") {
                kind[i].t = 1;
            } else if (op == "XOR") {
                kind[i].t = 2;
            } else if (op == "AND") {
                kind[i].t = 3;
            }
        } else {
            kind[i].t = -1;
            for (int j = 0; j < m; j++) {
                val[i][j] = x[j] - '0';
            }
        }
    }

    vector<int> a1(m), a2(m);

    for (int b = 0; b < m; b++) {
        int s1 = calc(b, 0);
        int s2 = calc(b, 1);

        if (s1 < s2) {
            a1[b] = 0;
            a2[b] = 1;
        } else if (s1 > s2) {
            a1[b] = 1;
            a2[b] = 0;
        } else {
            a1[b] = 0;
            a2[b] = 0;
        }
    }

    for (int i : a1) {
        cout << i;
    }
    cout << "\n";
    for (int i : a2) {
        cout << i;
    }


    return 0;
}