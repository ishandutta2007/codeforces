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
const int N = 11111;
const long long INF = 1e9 + 19;

int n;
int a[N];
long long t[N];
long long d[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                t[a[i] - a[j]]++;
        }
    int mx = a[n - 1];
    for (int i = 0; i <= mx; i++)
        for (int j = 0; j <= mx; j++)
            d[i + j] += t[i] *  1ll * t[j];

    //for (int i = 0; i < 10; i++) {
        //db2(t[i], d[i]);
    //}

    long long answer = 0;
    for (int i = 0; i <= mx; i++)
        for (int j = 0; j < i; j++)
            answer += t[i] * d[j];

    long long all = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            all += a[i] > a[j];
    all = all * all * all;

    //db2(answer, all);
    printf("%.17f\n", answer * 1.0 / all);
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