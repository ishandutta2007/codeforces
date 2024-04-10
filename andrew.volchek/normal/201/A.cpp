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

const ld pi = 3.14159265359;

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

//-----------------------------------------------------------------------------


int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int x;
    cin >> x;

    for (int i = 1; ; i++) {
        if (i & 1) {
            for (int t = 0; t < 2; t++) {

                int f1 = 0, f2 = 0, f4 = 0;

                for (int j = 0; j < i; j++) {
                    for (int h = 0; h < i; h++) {
                        int a = (bool(j & 1) ^ bool(h & 1)) == t;

                        if (!a) {
                            continue;
                        }

                        int g = 4;
                        if (i - 1 - j == j) {
                            g /= 2;
                        }

                        if (i - 1 - h == h) {
                            g /= 2;
                        }

                        if (g == 1) {
                            f1++;
                        } else if (g == 2) {
                            f2++;
                        } else {
                            f4++;
                        }
                    }
                }

                f2 /= 2;
                f4 /= 4;

                for (int j = 0; j <= f1; j++) {
                    for (int h = 0; h <= f2; h++) {
                        for (int k = 0; k <= f4; k++) {
                            if (j + h * 2 + k * 4 == x) {
                                cout << i << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        } else {
            int y = max(0, i / 2 - 1);
            for (int j = 0; j <= (y * y  + 1) / 2; j++) {
                if (j * 4 == x) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }


    return 0;
}