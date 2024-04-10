#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<bitset>
#include<random>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 100100;
const long long INF = 10000000000000000;
const long long m = 998244353;
long long fact[Y];
long long inv[Y];
bool dg[40000000];
long long pw(int b, long long et) {
    if (b == 1)return et;
    long long tmp = pw(b / 2, et);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
vector<long long>simple;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    long long D;
    cin >> D;
    int q;
    cin >> q;
    fact[0] = 1;
    long long d = sqrtl(D);
    while (d * d > D)--d;
    while ((d + 1) * (d + 1) <= D)++d;
    for (long long i = 1; i < Y; ++i) {
        fact[i] = fact[i - 1] * i % m;
        //inv[i] = pw(m - 2, i);
    }
    for (long long i = 2; i <= d; ++i) {
        if (D % i == 0) {
            simple.push_back(i);
            while (D % i == 0)D /= i;
        }
    }
    if (D != 1)simple.push_back(D);
    while (q--) {
        long long u, v;
        cin >> u >> v;
        long long g = gcd(max(u, v), min(u, v));
        u /= g;
        v /= g;
        int sm1 = 0, sm2 = 0;
        long long mn = 1;
        for (auto x : simple) {
            if (v % x == 0) {
                int cc = 0;
                while (v % x == 0) {
                    ++cc;
                    v /= x;
                }
                mn = (mn * fact[cc]) % m;
                sm1 += cc;
            }
            if (u % x == 0) {
                int cc = 0;
                while (u % x == 0) {
                    ++cc;
                    u /= x;
                }
                mn = (mn * fact[cc]) % m;
                sm2 += cc;
            }
        }
        long long rrr = (fact[sm1] * fact[sm2]) % m;
        long long rr = (((fact[sm1] * fact[sm2]) % m) * pw(m - 2, mn)) % m;
        cout << rr << "\n";
    }
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/