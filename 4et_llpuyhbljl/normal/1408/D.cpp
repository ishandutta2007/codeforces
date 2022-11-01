#pragma comment(linker, "/STACK:2759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const double INF = 1e8;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 2000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
int n, m;
long long arr[maxN];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    cin >> n >> m;
    vector < pair<long long, long long>>a(n);
    a.resize(n);
    fill(begin(arr), end(arr), -1LL);
    arr[maxN - 2] = -1;
    vector<pair<long long, long long>>b(m);
    for (auto& x : a)cin >> x.first >> x.second;
    for (int i = 0; i < m; ++i) {
        long long c, d;
        cin >> c >> d;
        b[i] = { c,d };
        arr[c] = max(arr[c], d);
    }
    for (int i = maxN - 2; i >= 0; --i)arr[i] = max(arr[i], arr[i + 1]);
    vector<int>ii;
    for (int i = 0; i < maxN - 1; ++i) {
        if (arr[i] != arr[i + 1])ii.push_back(i + 1);
    }
    vector<vector<pair<int, int>>>v(maxN);
    set<pair<long long, int>>s;
    long long add = 0;
    int jj = 0;
    vector<long long>rr(n);
    for (auto x : a) {
        s.insert({ arr[x.first] + 1 - x.second, jj });
        rr[jj] = arr[x.first] + 1 - x.second;
        for (int i = 0; i < ii.size(); ++i) {
            int vv = ii[i];
            if (x.first > vv)continue;
            long long rs = (vv - x.first + max(arr[vv] + 1 - x.second,0LL));
            v[vv - x.first].push_back({ jj,rs });
        }
        ++jj;
    }
    auto it = s.end();
    --it;
    long long ans = 0;
    long long tt;
    int uu;
    tie(tt, uu) = *it;
    ans = tt;
    for (int i = 1; i < maxN; ++i) {
        ++add;
        for (auto x : v[i]) {
            s.erase(s.find(make_pair(rr[x.first], x.first)));
            rr[x.first] = x.second - add;
            s.insert({ rr[x.first],x.first });
        }
        auto it = s.end();
        --it;
        long long tt;
        int uu;
        tie(tt, uu) = *it;
        ans = min(tt + add, ans);
    }
    cout << max(0LL, ans);
    return 0;
}