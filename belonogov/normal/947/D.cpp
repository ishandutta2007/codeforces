#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int N = 1e5 + 10;


struct Calc {
    vector<int> pref;
    vector<int> nota;

    Calc(char *s) {
        int n = strlen(s);
//        db(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i] != 'A';
        }
        pref.resize(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        nota.resize(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                nota[i] = 1;
            } else {
                nota[i] = nota[i - 1] + 1;
            }
            if (a[i] == 1) {
                nota[i] = 0;
            }
        }
    }

    int getSum(int l, int r) {
        return pref[r] - pref[l];
    }
    int getOne(int l, int r) {
        return min(r - l, nota[r - 1]);
    }
};

char s[N];
char t[N];


int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK
                   ".in", "r", stdin));
#endif
    scanf("%s%s", s, t);
    Calc g1(s);
    Calc g2(t);
    int q;
    scanf("%d", &q);
    for (int tt = 0; tt < q; tt++) {
//        db(tt);
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        l1--;
        l2--;
        int cntB1 = g1.getSum(l1, r1);
        int cntB2 = g2.getSum(l2, r2);
        int rem1 = g1.getOne(l1, r1);
        int rem2 = g2.getOne(l2, r2);
//        db2(cntB1, cntB2);
//        db2(rem1, rem2);
        bool ok = 0;
        if (cntB1 <= cntB2 && (cntB2 - cntB1) % 2 == 0) {
            if (cntB1 == cntB2) {
                ok = (rem1 % 3 == rem2 % 3) && rem1 >= rem2;
            }
            else {
                if (cntB1 == 0) {
                    if (rem1 > rem2) {
                        ok = 1;
                    }
                }
                else {
                    ok = rem1 >= rem2;
                }
            }
        }
//        if (cntB1 <= cntB2 && (cntB2 - cntB1) % 2 == 0 && rem1 % 3 == rem2 % 3) {
//            if (cntB2 == 0) {
//
//            } else {
//                ok = 1;
//            }
//        } else {
//            ok = 0;
//        }


        if (ok) {
            printf("1");
        } else {
            printf("0");
        }
    }
    puts("");


    return 0;
}