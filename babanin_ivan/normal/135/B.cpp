#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
#define getline botva55
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

struct point {
    int x, y;
};

struct line {
    int a, b, c;
};

point a[9];
bool used[20];
vector <point> b;

line getlin (point x, point y) {
    line l;
    l.a = y.y - x.y;
    l.b = x.x - y.x;
    l.c = y.x * x.y - x.x * y.y;
    return l;
}

int get(line l, point p) {
    int x = l.a * p.x + l.b * p.y + l.c;
    if (x == 0)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

ld dist (point x, point y) {
    return sqrt(ld((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) ));
}

void print() {
    printf("YES\n");
    for (int i = 0; i < 8; ++i)
        if (used[i])
            printf("%d ", i + 1);
    printf("\n");
    for (int i = 0; i < 8; ++i)
        if (!used[i])
            printf("%d ", i + 1);
    exit(0);
}

bool check1() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (i != j) {
                int x, y;
                for (int z = 0; z < 4; ++z)
                    if ((z != i) && (z != j)) {
                        x = z;
                        break;
                    }
                for (int z = 3; z >= 0; --z)
                    if ((z != i) && (z != j)) {
                        y = z;
                        break;
                    }

                bool f = true;
                int t1 = get(getlin(b[i], b[j]), b[x]);
                int t2 = get(getlin(b[i], b[j]), b[y]);
                if ((t1 == t2) || (t1 == 0) || (t2 == 0))
                    f = false;
                ld t3 = dist(b[i], b[x]);
                if (t3 != dist(b[i], b[y]))
                    f = false;
                if (t3 != dist(b[j], b[y]))
                    f = false;
                if (t3 != dist(b[j], b[x]))
                    f = false;
                if (abs(dist(b[i], b[j]) * dist(b[i], b[j]) - dist(b[i], b[x]) * dist(b[i], b[x]) - dist(b[j], b[x]) * dist(b[j], b[x])) > eps)
                    f = false;
                if (abs(dist(b[i], b[j]) * dist(b[i], b[j]) - dist(b[i], b[y]) * dist(b[i], b[y]) - dist(b[j], b[y]) * dist(b[j], b[y])) > eps)
                    f = false;
                if (f)
                    return f;
            }
    return false;
}

bool check2() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (i != j) {
                int x, y;
                for (int z = 0; z < 4; ++z)
                    if ((z != i) && (z != j)) {
                        x = z;
                        break;
                    }
                for (int z = 3; z >= 0; --z)
                    if ((z != i) && (z != j)) {
                        y = z;
                        break;
                    }

                bool f = true;
                int t1 = get(getlin(b[i], b[j]), b[x]);
                int t2 = get(getlin(b[i], b[j]), b[y]);
                if ((t1 == t2) || (t1 == 0) || (t2 == 0))
                    f = false;
                if (dist(b[j], b[x]) != dist(b[i], b[y]))
                    f = false;
                if (dist(b[i], b[x]) != dist(b[j], b[y]))
                    f = false;
                if (abs(dist(b[i], b[j]) * dist(b[i], b[j]) - dist(b[i], b[x]) * dist(b[i], b[x]) - dist(b[j], b[x]) * dist(b[j], b[x])) > eps)
                    f = false;
                if (abs(dist(b[i], b[j]) * dist(b[i], b[j]) - dist(b[i], b[y]) * dist(b[i], b[y]) - dist(b[j], b[y]) * dist(b[j], b[y])) > eps)
                    f = false;
                if (f)
                    return f;
            }
    return false;
}

void check() {
    bool f = true;
    b.clear();
    for (int i = 0; i < 8; ++i)
        if (used[i])
            b.pb(a[i]);
    if (!check1())
        f = false;
    b.clear();
    for (int i = 0; i < 8; ++i)
        if (!used[i])
            b.pb(a[i]);
    if (!check2())
        f = false;
    if (f)
        print();

}

void perebor(int pos, int kol) {
    if (kol == 4) {
        check();
        return ;
    }
    if (pos == 8)
        return ;
    used[pos] = true;
    perebor(pos + 1, kol + 1);
    used[pos] = false;
    perebor(pos + 1, kol);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    for (int i = 0; i < 8; ++i) 
        scanf("%d %d", &a[i].x, &a[i].y);
    perebor(0, 0);
    printf("NO\n");
    return 0;
}