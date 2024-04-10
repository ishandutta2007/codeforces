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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;
long long A, cf, cm, m;
long long answer;
pair < int, int > a[N];
int ans[N];
long long pref[N];


void read() {
    scanf("%d%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].fr);
    }
}

long long getSum(int l, int r) {
    return pref[r] - pref[l];
}

long long solve() {

    for (int i = 0; i < n; i++)
        a[i].sc = i;
    sort(a, a + n);
    reverse(a, a + n);

    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i].fr;

    int cur = -1;
    int where = -1;
    int whereH = -1;
    answer = -1;

    if (getSum(0, n) + m >= A * n) {
        answer = cf * 1ll  *n + A * 1ll * cm; 
        where = n;
        whereH = A;
    }
    else {

        for (int cntA = 0; cntA <= n; cntA++) {
            long long res = cntA * 1ll * cf;

            bool fail = 0;
            int myH = -1;
            cur = max(cur, cntA - 1);
            for (;; ) {
                long long use = A * 1ll * cntA - getSum(0, cntA);
                if (use > m) {
                    fail = 1;
                    break;
                }

                long long rem = m - use;
                if (a[cur + 1].fr * 1ll * (n - (cur + 1)) > getSum(cur + 1, n) + rem) {
                    cur++;
                }
                else {
                    //db(rem);
                    //db(cur);
                    assert(cur + 1 < n);
                    myH = (getSum(cur + 1, n) + rem) / (n - (cur + 1));
                    res += myH * cm;
                    break;
                }
            }
            if (fail) break;

            if (answer < res) {
                //db(cntA);
                //db2(res, myH);
                answer = res;
                where = cntA;
                whereH = myH;
            }
        }
    }
    long long myUse = 0;
    for (int i = 0; i < where; i++) {
        myUse += A - a[i].fr;
        ans[a[i].sc] = A;
    }
    for (int i = where; i < n; i++) {
        myUse += max(whereH - a[i].fr, 0);
        ans[a[i].sc] = max(a[i].fr, whereH);
    }


    return answer;
    //db2(m, myUse);
    assert(myUse <= m);

}

void genTest() {
    int T = 300;
    n = rand() % T + 1;
    A = rand() % T; 
    cf = rand() % T;
    cm = rand() % T;
    m = rand() % (T * 3);
    for (int i = 0; i < n; i++)
        a[i].fr = rand() % (A + 1);
}

void printAns() {
    printf("%lld\n", answer);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    puts("");
}

int b[N];
int c[N];

long long stupid() {
    for (int i = 0; i < n; i++)
        b[i] = a[i].fr;
    sort(b, b + n);
    reverse(b, b + n);  
    long long ans = -1;
    for (int cntA = 0; cntA <= n; cntA++) {
        long long res = 0;
        res = cntA * 1ll * cf;
        //db(res);
        long long tmpM = m;
        //db(m);
        for (int i = 0; i < n; i++)
            c[i] = b[i];
        for (int i = 0; i < cntA; i++) {
            tmpM -= A - b[i];
            c[i] = A;
        }
        //db(tmpM);
        if (tmpM < 0) break;
        for (int g = 1; g <= A; g++) {
            for (int i = 0; i < n; i++)
                if (c[i] < g) {
                    c[i]++;
                    tmpM--;
                } 
            if (tmpM >= 0)
                res += cm;
        }
        //db(tmpM);
        //db2(cntA, res);
        ans = max(ans, res);
    }


    return ans; 
}

void printTest() {
    cerr << n << " " << A << " " << cf << " " << cm << " " << m << endl;
    for (int i = 0; i < n; i++)
        cerr << a[i].fr << " ";
    cerr << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        auto r1 = solve();
        auto r2 = stupid();
        //db2(r1, r2);
        //if (r1 != r2) {
            //printTest();
        //}
        assert(r1 == r2);
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
            //db(stupid());
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}