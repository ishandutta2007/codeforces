#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 1000;
const int INF = 1e9;


int n;
int l[N];
int r[N];

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &l[i], &r[i]);
}

double solve() {
    long double ans = 0; 
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, r[i]);

    for (; mx > 0; mx--) {
        //cerr << "---------------mx: " << mx << endl;
        for (int i = 0; i < n; i++) {
            if (r[i] < mx) continue; 
            for (int mask = 1; mask < (1 << (n - 1)); mask++) {
                long double cof = (r[i] + 1 - max(l[i], mx + 1));
                //cerr << "cof 1 = : " << cof << endl;
                //cerr << "mask: " << mask << endl;
                for (int j = 0; j < n - 1; j++){
                    int cur = j + (i <= j);
                    if (((mask >> j) & 1) == 1) {
                        if (l[cur] <= mx && mx <= r[cur]) 
                            cof *= 1; 
                        else
                            cof = 0;
                    }
                    else {
                        int len = max(0, min(mx, r[cur] + 1) - l[cur]);
                        cof *= len; 
                    }
                }
                ans += mx * cof;
                //cerr << "
            }
        }
        //cerr << "i--- mid  ans: " << ans << endl;

        for (int mask = 1; mask < (1 << n); mask++) {
            long double cof = 1;   
            int cntBit = __builtin_popcount(mask);
            if (cntBit < 2) continue;
            for (int i = 0; i < n; i++)
                if (((mask >> i) & 1) == 1) {
                    if (l[i] > mx || r[i] < mx) 
                        cof = 0; 
                }
                else {
                    cof *= max(0, (min(r[i] + 1, mx) - l[i]));
                }
            //cerr << "cof mask: " << cof << " " << mask << endl;
            ans += cof * mx;
        }
        //cerr << "ans: " << ans << endl;
    }
    long double mulLen = 1;
    for (int i = 0; i < n; i++) {
        mulLen *= (r[i] - l[i] + 1);
    }
    //cerr << "ans: mulLen: " << ans << " " << mulLen << endl;
    return ans / mulLen;
    //printf("%.15lf\n", (double)(ans / mulLen));
}

void printAns(double x) {
    printf("%.15lf\n", x);
}

void genTest() {
    n = 4;
    int T = 6;
    for (int i = 0; i < n; i++) {
        l[i] = rand() % T;
        r[i] = rand() % T;
        if (l[i] > r[i]) swap(l[i], r[i]);
    }
}

int a[N];
int sum;

void rec(int t) {
    if (t == n) {
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx1) {
                mx1 = a[i];
            }
            if (mx1 > mx2) swap(mx1, mx2);
        }
        sum += mx1;
        return;
    }
    for (int i = l[t]; i <= r[t]; i++) {
        a[t] = i;
        rec(t + 1);
    }
}

double stupid() {
    sum = 0;
    rec(0); 
    double comb = 1;
    for (int i = 0; i < n; i++)
        comb *= (r[i] - l[i] + 1);
    return sum / comb;
}

void printTest() {
    cerr << n << endl;
    for (int i = 0; i < n; i++)
        cerr << l[i] << " " << r[i] << endl;
}

void stress() {
    for (int tt = 0; tt < 100; tt++) {
        cerr << "test id: " << tt << endl;
        genTest();
        double r1 = solve();
        double r2 = stupid();
        if (!equal(r1, r2)) {
            cerr << "r1 r2: " << r1 << " " << r2 << endl;
            printTest();
            exit(0);
        }
    }

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            printAns(solve());
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}