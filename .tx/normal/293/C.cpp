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
#include <cmath>

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

lint n;

int main() {
    cin >> n;
    if (n % 3 != 0) {
        cout << 0;
        return 0;
    }
    n /= 3;
    
    vei dels;
    lint sq = ceil(sqrt(n + .0));
    
    for (lint i = 2; i <= sq; i++) {
        if (n % i == 0) {
            dels.push_back(i);
            if (i * i != n) {
                dels.push_back(n / i);
            }
        }
    }
    
    sort(all(dels));
    
    int len = sz(dels);
    lint ans = 0;
    for (int i = 0; i < len; i++) {
        lint a = dels[i];
        lint na = (n / a);
        for (int j = 0; j < len; j++) {
            lint b = dels[j];
            if (b >= na) break;
            if (na % b != 0) {
                continue;
            }
            
            
            lint c = na / b;
            if (c < 2 || n % c != 0) {
                continue;
            }
            // && (a + b - c) & 1 == 0 && (a - b + c) & 1 == 0 && (-a + b + c) & 1 == 0
            if (a + b - c > 1 && a - b + c > 1 && -a + b + c > 1 && ((a + b - c) & 1) == 0 && ((a - b + c) & 1) == 0 && ((-a + b + c) & 1) == 0) {
                ans++;
                //cout << a << " " << b << " " << c << endl;
            }
        }
    }
    
    cout << ans;
    

    return 0;
}
 //xjslpy