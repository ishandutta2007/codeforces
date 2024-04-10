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
#include <tuple>
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

pair<string, string> split(string s) {
    int cnt = 0;
    int p = 0;
    while (p < s.size()) {
        cnt += s[p] == '/';
        if (cnt == 3) {
            break;
        }
        p++;
    }
    return mp(string(s.begin(), s.begin() + p), string(s.begin() + p, s.end()));
}

char s[1000];

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("assassination.in", "r", stdin);
    //freopen("abyss.out", "w", stdout);
#endif

    map<string, set<string>> a;

    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s\n", s);
        auto res = split(s);
        a[res.fst].insert(res.snd);
    }

    vector<pair<vector<string>, string>> b;
    for (auto kv : a) {
        b.pb(mp(vector<string>(kv.snd.begin(), kv.snd.end()), kv.fst));
    }

    sort(b.begin(), b.end());

    vector<vector<string>> ans;
    for (int i = 0; i < b.size(); i++) {
        vector<string> c;
        int j = i;
        while (j < b.size() && b[i].fst == b[j].fst) {
            c.pb(b[j].snd);
            j++;
        }
        if (c.size() > 1) {
            ans.pb(c);
        }
        i = j - 1;
    }

    printf("%d\n", (int)ans.size());

    for (auto p : ans) {
        for (int i = 0; i < p.size(); i++) {
            if (i) {
                printf(" ");
            }
            printf("%s", p[i].c_str());
        }
        printf("\n");
    }

    return 0;
}