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

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;


int main(){
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    x--;
    auto f = [&](int y) {
        int nn = n - y * 2;
        int mm = m - y * 2;
        //db2(nn, mm);
        if (nn <= 0 || mm <= 0) {
            return 0;
        }
        return (nn * mm + 1) / 2;
    };
    cout << f(x) - f(x + 1) << endl;



    return 0;
}