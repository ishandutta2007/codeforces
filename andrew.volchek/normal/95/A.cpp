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
#define ld double
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
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    vector<string> a;
    string b;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        a.pb(x);
    }

    cin >> b;


    vector<int> bad(b.size(), 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + a[i].size() - 1 < b.size(); j++) {
            bool all = true;
            for (int h = 0; h < a[i].size(); h++) {
                all &= tolower(b[j + h]) == tolower(a[i][h]);
            }
            if (all) {
                for (int h = 0; h < a[i].size(); h++) {
                    bad[j + h] = 1;
                }
            }
        }
    }

    char L;
    cin >> L;


    cerr << L << endl;


    for (int i = 0; i < b.size(); i++) {
        if (bad[i]) {
            bool u = isupper(b[i]);

            if (tolower(b[i]) != L) {
                b[i] = u ? toupper(L) : L;
            } else {
                char c = 'a';
                while (tolower(b[i]) == c) {
                    c++;
                }
                b[i] = u ? toupper(c) : c;
            }
        }
    }

    cout << b << endl;


    return 0;
}