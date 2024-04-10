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
#include <functional>

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
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int,int> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        q[a[i]]++;
    }

    for (auto it = q.rbegin(); it != q.rend(); it++) {
        if (it->S % 2 == 1) {
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");







    return 0;
}