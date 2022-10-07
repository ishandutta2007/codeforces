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
const int N = 555000;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

struct pnt {
    long long x, y;
    pnt () { }
    pnt (long long x, long long y): x(x), y(y) { }
    pnt operator + (pnt A) {
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A) {
        return pnt(x - A.x, y - A.y);
    }
    long long operator * (pnt A) {
        return x * A.y - y * A.x;
    }
    long long operator % (pnt A) {
        return x * A.x + y * A.y;
    }
    long long len2() {
        return x * x + y * y;
    }
    void read() {
        scanf("%lld%lld", &x, &y);
    }
};

pnt p[N];
long long val[N];
long long mou[N];
long long pref[N];
long long prefX[N];
long long prefY[N];
int n;


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        p[i].read();
    reverse(p, p + n);
}

long long getSum(int l, int r, long long * pref) {
    if (l <= r) 
        return (pref[r] - pref[l] + MOD) % MOD;
    return (pref[n] - pref[l] + pref[r] - pref[0] + 2 * MOD) % MOD;
}

long long getStairE(int l, int r) {
    if (l == r) return 0;
    assert(l <= r);
    long long val = (mou[r] - mou[l] + MOD) % MOD;
    long long seg = getSum(l, r, pref);
    val = (val - seg * l % MOD + MOD) % MOD;
    return val;
}

long long getStair(int l, int r) {
    //db2(l, r);
    if (l <= r) return getStairE(l, r);
    long long s1 = getStairE(l, n);
    long long s2 = getStairE(0, r);
    //db2(s1, s2);
    long long seg = getSum(0, r, pref);
    long long res = (s1 + s2 + seg * (n - l)) % MOD;
    return res;
}

long long solve() {
    long long answer = 0;
    long long area = 0; 
    for (int i = 0; i < n; i++)
        val[i] = (p[i] * p[(i + 1) % n] % MOD + MOD) % MOD;
    for (int i = 0; i < n; i++)
        area += p[i] * p[(i + 1) % n];


    for (int i = 0; i < n; i++) {
        mou[i + 1] = (mou[i] + val[i] * (i + 1) % MOD + MOD) % MOD;
    }
    for (int i = 0; i < n; i++) {
        //pref[i + 1] = (pref[i] + val[i]) % MOD;
        //prefX[i + 1] = (prefX[i] + p[i].x) % MOD;
        //prefY[i + 1] = (prefY[i] + p[i].y)  % MOD;
        pref[i + 1] = (pref[i] + val[i] + MOD) % MOD;
        prefX[i + 1] = (prefX[i] + p[i].x + MOD) % MOD;
        prefY[i + 1] = (prefY[i] + p[i].y + MOD) % MOD;
    }
    //for (int i = 0; i < n; i++)
        //cerr << val[i] << " ";
    //cerr << endl;
    //for (int i = 0; i <= n; i++)
        //cerr << mou[i] << " ";
    //cerr << endl;

    //for (int i = 0; i < n; i++)
        //cerr << p[i].x << " " << p[i].y << endl;

    for (int i = 0; i <= n; i++) {
        assert(0 <= val[i] && val[i] < MOD);
        assert(0 <= mou[i] && mou[i] < MOD);
        assert(0 <= pref[i] && pref[i] < MOD);
        assert(0 <= prefX[i] && prefX[i] < MOD);
        //db(prefY[i]);
        assert(0 <= prefY[i] && prefY[i] < MOD);
    }

    assert(area > 0);

    long long sum = 0; 
    int cur = 1; 
    for (int i = 0; i < n; i++) {
        //cerr << endl;
        //db(sum);
        //assert(sum < 5e18);
        for (; sum < (area + 1) / 2; ) {
            int ncur = (cur + 1) % n;
            sum -= p[cur] * p[i];
            sum += p[cur] * p[ncur];
            sum += p[ncur] * p[i];
            cur = ncur;
            //db2(cur, sum);
        }       
        //db2(sum, area);
        //db2(i, cur);
        int cnt = (i + n - cur) % n;
        assert(cnt > 0);
        //db(cnt);
        cnt--;
        long long res = area % MOD * cnt % MOD;  
        //db(res);
        int prev = (i - 1 + n) % n;
        long long stair = getStair(cur, prev);            
        //db(stair);
        res = (res - stair * 2 + MOD + MOD) % MOD;
        res = (res - 2 * cnt * val[prev] % MOD + MOD) % MOD;
        long long XX = getSum(cur, prev, prefX);
        long long YY = getSum(cur, prev, prefY);
        //db2(XX, YY);
        long long tmp = (2 * (XX * p[i].y - YY * p[i].x) % MOD + MOD) % MOD;
        //db(tmp);
        res = (res + tmp) % MOD;
        answer = (answer + res) % MOD;
        //db(answer);
        //if (i == 1) return;

        sum -= p[cur] * p[i];
        sum -= p[i] * p[(i + 1) % n];
        sum += p[cur] * p[(i + 1) % n];
    }

    return answer;

}

void printAns(long long x) {
    cout << x << endl;
}

pnt O;
pnt st[N];

bool cmpO(pnt A, pnt B) {
    A = A - O;
    B = B - O;
    return A * B > 0 || (A * B == 0 && A.len2() < B.len2());
}

void genTest() {
    for (;;) {
        n = 5;
        int T = 20e8;
        for (int i = 0; i < n; i++) {
            p[i] = pnt(rand() % T - T / 2, rand() % T - T / 2);
        }
        
        for (int i = 0; i < n; i++)
            if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
                swap(p[i], p[0]);
        O = p[0];
        sort(p, p + n, cmpO);
        int cur = 0;
        //db(cur);
        for (int i = 0; i < n; i++) {
            for (; cur >= 2 && (st[cur - 1] - st[cur - 2]) * (p[i] - st[cur - 1]) <= 0; cur--);
            st[cur++] = p[i];
        }
        n = cur;
        for (int i = 0; i < n; i++)
            p[i] = st[i];
        //db("here");
        if (n <= 3) {
            //db("genTest fail");
            continue;
        }
        break;
    }
}

long long calcArea(vector < pnt > p) {
    long long area = 0;
    for (int i = 0; i < (int)p.size(); i++) 
        area += p[i] * p[(i + 1) % p.size()];
    return area;
}

long long stupid() {
    long long answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n - (i == 0); j++) {
            vector < pnt > g;
            for (int t = i; ; t = (t + 1) % n) {
                g.pb(p[t]);
                if (t == j) break;
            }
            long long s1 = calcArea(g);
            g.clear();
            for (int t = j; ; t = (t + 1) % n) {
                g.pb(p[t]);
                if (t == i) break;
            }
            long long s2 = calcArea(g);
            answer = (answer + abs(s1 - s2)) % MOD;

        }
    return answer;
}


void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        //db("solve");
        auto r1 = solve();
        //db("stupid");
        auto r2 = stupid();
        db(n);
        db2(r1, r2);
        //if (r1 != r2){
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
            printAns(solve());
            //printAns(stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}