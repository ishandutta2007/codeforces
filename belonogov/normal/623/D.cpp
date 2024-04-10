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
const int N = 111;
const long long INF = 1e9 + 19;

int n;
long double p[N];
int x[N];
long double prob[N];
long double pref[N];
long double suf[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        //p[i] = x / 100.0
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
        tmp += x[i];
    assert(tmp == 100);
}

long double binPow(long double x, int b) {
    long double res = 1;
    for (; b > 0; b /= 2) {
        if (b & 1)
            res = res * x;
        x *= x;
    }
    return res;
}

void solve() {
    long double answer = 0; 
    sort(x, x + n); 
    vector < pair < int, int > > b;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && x[i] == x[j]; i++);
        b.pb(mp(x[j], i - j));
    }
    int m = b.size();
    for (int i = 0; i < m; i++)
        p[i] = b[i].fr / 100.0;

    for (int i = 0; i < m; i++)
        prob[i] = p[i];
    

    long double mul = 1;
    for (int i = 0; i < m; i++)
        mul *= binPow(p[i], b[i].sc);

    answer += n * mul;

    long double sum = mul;

    //int gg = 0;
    int t;
    //for (t = n + 1; sum < 1 - 1e-11 ;) {
    for (t = n + 1; ; ) {
        //if (t % 1000 == 0 && clock() * 1.0 / CLOCKS_PER_SEC > 1.5) {
            //db(t);
            //break;
        //}
        //if (t > gg * 1000) {
            //gg++;
            //if (clock() * 1.0 / CLOCKS_PER_SEC > 1.5) {
                //db(t);
                //break;
            //}
        //}
        int id = -1;
        long double best = -1;
        long double mulAll = 1;
        for (int i = 0; i < m; i++) {
            mulAll *= binPow(prob[i], b[i].sc);
        }
        if (mulAll > 1 - 1e-14) break;
        for (int i = 0; i < m; i++) {
            long double cur = mulAll / prob[i] * (1 - prob[i]) * p[i];
            if (best < cur) {
                best = cur;
                id = i;
            }
        } 
        long double nprob = prob[id] + (1 - prob[id]) * p[id];
        for (int j = 0; j < b[id].sc; j++, t++) {
            answer += best * t;
            sum += best;
            best /= prob[id];
            best *= nprob;
        }
        //if (t % 10000 == 0)
            //epr("%.80f\n", (long double)best);
        prob[id] = nprob;
    }
    //db(t);
    //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    
    //for (int i = 0; i < n; i++)
        //cerr << prob[i] << " ";
    //cerr << endl;

    printf("%.17f\n", (double)answer);
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