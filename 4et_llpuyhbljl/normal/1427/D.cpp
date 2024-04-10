#pragma comment(linker, "/STACK:9759095000")
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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
bool valid(vector<int>cc) {
    for (int i = 0; i < cc.size(); ++i) {
        if (i != cc[i])return false;
    }
    return true;
}
vector<int> build_idx(vector<int>c) {
    vector<int>res(c.size());
    for (int i = 0; i < c.size(); ++i) {
        res[c[i]] = i;
    }
    return res;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
   // file_inc();
    int n;
    cin >> n;
    vector<int>c(n), ID(n);
    vector<vector<int>>q;
    for (auto& x : c) {
        cin >> x;
        --x;
    }
    while (!valid(c)) {
        ID = build_idx(c);
        int i1 = 0, i2 = 0;
        for (int i = 1; i < ID.size(); ++i) {
            if (ID[i] < ID[i - 1]) {
                i1 = ID[i - 1];
                i2 = ID[i];
                break;
            }
        }
        int j2 = i2 + 1;
        while (j2 < n && c[j2 - 1] == c[j2] - 1)++j2;
        vector<int>cc;
        q.push_back({});
        if (i2 != 0) {
            q.back().push_back(i2);
        }
        q.back().push_back(j2 - i2);
        q.back().push_back(i1 - j2 + 1);
        if (i1 + 1 != n) {
            q.back().push_back(n - i1 - 1);
        }
        if (i1 + 1 != n) {
            for (int i = i1 + 1; i < n; ++i)cc.push_back(c[i]);
        }
        for (int i = j2; i <= i1; ++i)cc.push_back(c[i]);
        for (int i = i2; i < j2; ++i)cc.push_back(c[i]);
        for (int i = 0; i < i2; ++i)cc.push_back(c[i]);
        c = cc;
    }


    cout << q.size() << "\n";
    for (auto x : q) {
        cout << x.size() << " ";
        for (auto y : x)cout << y << " ";
        cout << "\n";
    }
    return 0;
}