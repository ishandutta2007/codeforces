#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    // gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int cnt[2][10];
    memset(cnt, 0, sizeof cnt);

    string s;
    cin >> s;

    for (char c : s) {
        cnt[0][c - '0']++;
        cnt[1][c - '0']++;
    }

    string ans[2];

    pair<int,int> bst(-1, -1);

    for (int i = 1; i <= 9; i++) {
        int j = 10 - i;

        if (cnt[0][i] && cnt[1][j]) {
            cnt[0][i]--;
            cnt[1][j]--;


            int res = 0;
            for (int h = 0; h <= 9; h++) {
                res += min(cnt[0][h], cnt[1][9 - h]);
            }

            chmax(bst, mp(res, i));

            cnt[0][i]++;
            cnt[1][j]++;
        }
    }


    if (bst.fst != -1) {

        cnt[0][bst.snd]--;
        cnt[1][10 - bst.snd]--;

        ans[0] += '0' + bst.snd;
        ans[1] += '0' + 10 - bst.snd;

        while (true) {
            bool found = false;
            for (int i = 0; i <= 9; i++) {
                int j = 9 - i;
                if (cnt[0][i] && cnt[1][j]) {
                    cnt[0][i]--;
                    cnt[1][j]--;
                    ans[0] += '0' + i;
                    ans[1] += '0' + j;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
    }

    reverse(ans[0].begin(), ans[0].end());
    reverse(ans[1].begin(), ans[1].end());

    while (cnt[0][0] && cnt[1][0]) {
        ans[0] += '0';
        ans[1] += '0';
        cnt[0][0]--;
        cnt[1][0]--;
    }


    reverse(ans[0].begin(), ans[0].end());
    reverse(ans[1].begin(), ans[1].end());

    for (int i = 0; i < 10; i++) {
        while (cnt[0][i]) {
            ans[0] += '0' + i;
            cnt[0][i]--;
        }

        while (cnt[1][i]) {
            ans[1] += '0' + i;
            cnt[1][i]--;
        }
    }

    reverse(ans[0].begin(), ans[0].end());
    reverse(ans[1].begin(), ans[1].end());

    cout << ans[0] << endl;
    cout << ans[1] << endl;


    return 0;
}