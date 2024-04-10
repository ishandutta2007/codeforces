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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 2e6 + 10;
const int INF = 1e9;

int n, q;
int a[N];
long long b[N];
int go[N];
int answer;

void read() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < q; i++)
        cin >> b[i];
}

void run(int pos) {
    int cnt = 0;
    if (pos > n) return;
    for (int i = pos; i < pos + n; i = go[i], cnt++); //cerr << "i: " << i << endl; }
    answer = min(answer, cnt);
}


void solve() {
    for (int i = 0; i < n; i++)
        a[i + n] = a[i];
    for (int t = 0; t < q; t++) {
        long long sz = b[t];
        int cur = 0;
        long long sum = 0;
        for (int i = 0; i <= n * 2; i++) {
            for (; cur < n * 2 && sum + a[cur] <= sz; cur++)
                sum += a[cur];
            go[i] = cur;
            sum -= a[i];
        }
        //for (int i = 0; i < n * 2; i++)
            //cerr << go[i] << " ";
        //cerr << endl;
        int mn = 0;
        for (int i = 0; i < n; i++)
            if (go[i] - i < go[mn] - mn)
                mn = i;
        //cerr << "mn: " << mn << endl;
        answer = n;
        for (int i = mn; i <= go[mn]; i++)
            run(i);
        printf("%d\n", answer);
    }

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        for (int tt = 0; tt < 1; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}