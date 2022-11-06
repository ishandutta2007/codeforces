#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef long long int lint;

typedef vector<int> vei;
typedef vector< vei > veii;
typedef vector<double> ved;
typedef vector<lint> vel;
typedef vector<string> ves;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define scd(a) scanf("%lf", &a)
#define scdd(a, b) scanf("%lf%lf", &a, &b)

#define pri(a) printf("%d\n", a)
#define prii(a, b) printf("%d %d\n", a, b)
#define prisp(a) printf("%d ", a)
#define prd(a) printf("%.9lf\n", a)
#define prdd(a, b) printf("%.9lf %.9lf\n", a, b)
#define prdsp(a) printf("%.9lf ", a)

#define prs(s) printf("%s\n", s)
#define prssp(s) printf("%s ", s)

#define forr(i, st, n) for (int i = (st); i < (n); ++i)
#define foi(n) forr(i, 0, n)
#define foj(n) forr(j, 0, n)
#define fok(n) forr(k, 0, n)
#define foist(st, n) forr(i, st, n)
#define fojst(st, n) forr(j, st, n)
#define fokst(st, n) forr(k, st, n)
#define forit(i, a, type) for (type::iterator i = a.begin(); i != a.end(); ++i)

#define mast(a, n, type) a = new type[n]; memset(a, 0, (n) * sizeof(type))
#define masi(a, n) mast(a, n, int)
#define masd(a, n) mast(a, n, double) 
#define masl(a, n) mast(a, n, lint)

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)(a.size())
#define lng(a) (int)(a.length())

#define fiopr(s) freopen(s, "r", stdin)
#define fiopw(s) freopen(s, "w", stdout)

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    
    bool operator < (const point &r) const {
        return x == r.x ? y < r.y : x < r.x;
    }
};

int main() {
    int n;
    sci(n);
    string s, t;
    cin >> s >> t;
    int k1, k2, ko;
    k1 = k2 = ko = 0;
    foi(lng(s)) {
        if (s[i] == '1' && t[i] == '1') {
            ko++;
        } else if (s[i] == '1') {
            k1++;
        } else if (t[i] == '1') {
            k2++;
        }
        
    }
    
    int n1 = ko / 2;
    int n2 = ko / 2;
    bool fl = true;
    if (ko % 2 == 1) {
        n1++;
        fl = false;
    }
    while (k1 > 0 || k2 > 0) {
        if (fl) {
            if (k1 > 0) {
                n1++;
                k1--;
            } else {
                k2--;
            }
        } else {
            if (k2 > 0) {
                n2++;
                k2--;
            } else {
                k1--;
            }
        }
        fl = !fl;
    }

    if (n1 == n2) {
        cout << "Draw";
    } else if (n1 > n2) {
        cout << "First";
    } else {
        cout << "Second";
    }
    
    
    return 0;
}
 //mbcmht