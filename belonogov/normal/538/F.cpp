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
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9;

int n;
int a[N];
int d[N];
//vector < pair < int, int > > b; // t type

void read() {
    //int n = 51;
    //for (int i = 1; i <= n; i++) {
        //cerr << i << " " << n / i << endl;
    //}
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
}

void add(int l, int r) { // [l , r];
    //epr("[%d, %d]\n", l, r);
    d[l]++;
    d[r + 1]--;
    //b.pb(mp(l, 1)); 
    //b.pb(mp(r + 1, -1));
}

vector < int > solve() {
    for (int i = 0; i <= n; i++)
        d[i] = 0;
    for (int i = 2; i <= n; i++) {
        int x = i - 2;  
        int k = 1;
        for (; ; ) {
            int v = x / k;
            int last = n - 1;
            if (v != 0)
                last = x / v;
            assert(last >= k);
            if (a[v + 1] > a[i]) {
                add(k, last);
            }
            k = last + 1;
            if (k >= n) break;
        }
    } 
    int sum = 0;
    vector < int > ans(n);
    for (int i = 1; i < n; i++) {
        sum += d[i];
        //for (; cur < (int)b.size() && b[cur].fr <= i; cur++)
            //sum += b[cur].sc;
        ans[i] = sum;
    }
    return ans;
}

void printAns(vector < int > ans) {
    for (int i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

}

vector < int > stupid() {
    vector < int > rr(n);
    for (int v = 1; v < n; v++) {
        for (int k = 1; k < n; k++) {
            int l = k * (v - 1) + 2;
            int r = k * v + 1;
            for (int j = l; j <= r; j++)
                if (j <= n && a[v] > a[j])
                    rr[k]++;
        }
    }
    return rr;
}

void stress() {
    for (int tt  = 0;;tt++) {
        cerr << "test id: " << tt << endl;
        n = 200000;
        int T = 100;
        for (int i = 1; i <= n; i++) {
            a[i] = rand() % T;
        }
        auto r1 = solve();
        cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        //auto r2 = stupid();
        //for (auto x: r1)
            //cerr << x << " ";
        //cerr << endl;
        //for (auto x: r2)
            //cerr << x << " ";
        //cerr << endl;
        //for (int i = 1; i < n; i++)
            //assert(r1[i] == r2[i]);
    }
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
            //stupid();
            //solve();
            printAns(solve());
            //printAns(stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}