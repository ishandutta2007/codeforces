#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct pnt  {
    long long x, y;
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    long long len2() {
        return x * x + y * y;
    }
};

int n;
int a[N];
pnt p[N];
pnt st[N];
pnt tmp[N];
long long answer;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

bool cmpX(pnt A, pnt B) {
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool cmpY(pnt A, pnt B) {
    return A.y < B.y || (A.y == B.y && A.x < B.x);
}

long long sqr(long long x) {
    return x * x;
}

void calc(int l, int r) {
    if (r - l == 1) 
        return;
    int mid = (l + r) / 2;
    int X = p[mid].x;
    calc(l, (l + r) / 2);
    calc((l + r) / 2, r);
    merge(p + l, p + mid, p + mid, p + r, tmp + l, cmpY);
    memcpy(p + l, tmp + l, sizeof(pnt) * (r - l));
    int cur = 0; 
    for (int i = l; i < r; i++) {
        if (sqr(p[i].x - X) >= answer) continue;
        for (int j = cur - 1; j >= 0 && sqr(st[j].y - p[i].y) < answer; j--)
            answer = min(answer, (st[j] - p[i]).len2());
        st[cur++] = p[i];
    }  
}


void solve() {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        p[i] = pnt(s, i + 1);
    }
    sort(p, p + n, cmpX);  

    answer = INF * 1ll * INF;
    calc(0, n);
    cout << answer << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}