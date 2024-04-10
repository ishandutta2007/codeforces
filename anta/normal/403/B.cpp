#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

vector<bool> isprime;
vector<int> primes;
void sieve(int n){
    if((int)isprime.size() >= n+1) return;
    isprime.assign(n+1, true);
    isprime[0] = isprime[1] = false;
    int sqrtn = (int)(sqrt(n * 1.) + .5);
    for(int i = 2; i <= sqrtn; i ++) if(isprime[i]) {
        for(int j = i * i; j <= n; j += i)
            isprime[j] = false;
    }
    primes.clear();
    for(int i = 2; i <= n; i ++) if(isprime[i])
        primes.push_back(i);
}

typedef vector<pair<int,int> > Factors;
void primeFactors(int x, Factors &out_v) {
    out_v.clear();
    int sqrtx = (int)(sqrt(x*1.) + 10.5);
    sieve(sqrtx);
    each(p, primes) {
        if(*p > sqrtx) break;
        if(x % *p == 0) {
            int t = 1;
            x /= *p;
            while(x % *p == 0) {
                t ++;
                x /= *p;
            }
            out_v.push_back(make_pair(*p, t));
        }
    }
    if(x != 1) out_v.push_back(make_pair(x, 1));
}

template<typename Op> inline Factors combineFactors(Op op, int id, const Factors &a, const Factors &b) {
    Factors c;
    int an = a.size(), bn = b.size();
    int ai = 0, bi = 0;
    while(ai < an || bi < bn) {
        typename Factors::value_type::first_type p; int q;
        if(ai < an && (bi >= bn || a[ai].first < b[bi].first)) {
            p = a[ai].first, q = op(a[ai].second, id);
            ai ++;
        }else if(bi < bn && (ai >= an || a[ai].first > b[bi].first)) {
            p = b[bi].first, q = op(id, b[bi].second);
            bi ++;
        }else {
            p = a[ai].first, q = op(a[ai].second, b[bi].second);
            ai ++, bi ++;
        }
        if(q != 0) c.push_back(mp(p, q));
    }
    return c;
}

Factors gcdFactors(const Factors &a, const Factors &b) {
    return combineFactors<const int&(*)(const int&,const int&)>(std::min<int>, 0, a, b);
}
ostream &outFactors(const Factors &a) {
    if(a.empty()) return cerr << "1";
    each(i, a) {
        if(i != a.begin()) cerr << " ";
        cerr << i->first << "^" << i->second;
    }
    return cerr;
}

int a[5000], b[5000];
int dp[5001][5001];
int main() {
    //{2},{2,3}
    //1, 2: {},{2,3} -> {},{2,3}
    //2, 1: {},{3} -> {},{3}
    //()
    //DP
    //subset
    //gcd(a[1..i])i
    //
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d", &b[i]);
    vector<Factors> fs(n), gs(n+1);
    rep(i, n) {
        primeFactors(a[i], fs[i]);
        if(i == 0) gs[i] = fs[i];
        else gs[i] = gcdFactors(gs[i-1], fs[i]);
//      cerr << i << ": "; outFactors(fs[i]) << ", "; outFactors(gs[i]) << endl;
    }
    vector<int> fvs(n), gvs(n+1);
    rep(i, n) {
        int x = 0;
        each(j, fs[i]) x += (binary_search(b, b+m, j->first) ? -1 : 1) * j->second;
        fvs[i] = x;
    }
    rer(i, 0, n) {
        int x = 0;
        each(j, gs[i]) x += (binary_search(b, b+m, j->first) ? -1 : 1) * j->second;
        gvs[i] = x;
    }
    rer(i, 0, n) rer(j, 0, n) dp[i][j] = -INF;
    dp[n][n] = 0;
    for(int i = n; i > 0; i --) rer(j, 0, n) {
        int x = dp[i][j];
        if(x == -INF) continue;
//      cerr << i << ", " << j << ": " << x << endl;
        amax(dp[i-1][j], x + (fvs[i-1] - gvs[j]));
        amax(dp[i-1][i-1], x + (fvs[i-1] - gvs[i-1]));
    }
    int ans = -INF;
    rer(j, 0, n) amax(ans, dp[0][j]);
    printf("%d\n", ans);
    return 0;
}