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
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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

int n;

int xx1 = -1, xx2 = -1;
int yy1 = -1, yy2 = -1;


int ask(int x1, int y1, int x2, int y2) {

    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int res = 0;
    cin >> res;



    /*int x11 = 2, y11 = 2, x12 = 2, y12 = 2;
    int x21 = 3, y21 = 4, x22 = 3, y22 = 5;

    //int res = 0;
    if (x1 <= x11 && x12 <= x2 && y1 <= y11 && y12 <= y2) {
        res++;
    }

    if (x1 <= x21 && x22 <= x2 && y1 <= y21 && y22 <= y2) {
        res++;
    }*/

    if (xx1 != -1 && x1 <= xx1 && xx2 <= x2) {
        res--;
    }

    if (yy1 != -1 && y1 <= yy1 && yy2 <= y2) {
        res--;
    }

    //assert(res >= 0);

    return res;
}




int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
        //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif


    cin >> n;

    int x[2][2];

    for (int i = 0; i < 2; i++) {
        int lo = 0, hi = n + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;

            if (ask(1, 1, mid, n)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        int lo2 = 0, hi2 = hi + 1;
        while (hi2 - lo2 > 1) {
            int mid = (lo2 + hi2) >> 1;
            if (ask(mid, 1, hi, n)) {
                lo2 = mid;
            } else {
                hi2 = mid;
            }
        }


        x[i][0] = lo2, x[i][1] = hi;
        //cout << lo2 << " " << hi << endl;



        xx1 = x[i][0];
        xx2 = x[i][1];

        //mX ^= 1;
    }

    xx1 = -1;


    int y[2][2];

    for (int i = 0; i < 2; i++) {
        int lo = 0, hi = n + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;

            if (ask(1, 1, n, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        int lo2 = 0, hi2 = hi + 1;
        while (hi2 - lo2 > 1) {
            int mid = (lo2 + hi2) >> 1;
            if (ask(1, mid, n, hi)) {
                lo2 = mid;
            } else {
                hi2 = mid;
            }
        }

        y[i][0] = lo2, y[i][1] = hi;


        yy1 = y[i][0];
        yy2 = y[i][1];

       // mY ^= 1;
    }

    yy1 = -1;

    if (!ask(x[0][0], y[0][0], x[0][1], y[0][1]) || !ask(x[1][0], y[1][0], x[1][1], y[1][1])) {
        for (int i = 0; i < 2; i++) {
            //swap(x[0][i], x[1][i]);
            swap(y[0][i], y[1][i]);
        }
    }

    if (!ask(x[0][0], y[0][0], x[0][1], y[0][1]) || !ask(x[1][0], y[1][0], x[1][1], y[1][1])) {
        assert(0);
    }

    cout << "! " << x[0][0] << " " << y[0][0] << " " << x[0][1] << " " << y[0][1] << " ";
    cout << x[1][0] << " " << y[1][0] << " " << x[1][1] << " " << y[1][1] << endl;



    return 0;
}