#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define aut(v, x) __typeof(x) v = (x)
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<ll> vl; typedef pair<ll,ll> pll; typedef vector<pll> vpll; typedef vector<string> vs;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

typedef vector<ll> Vec;
typedef vector<Vec> Mat;
#define MOD 1000000007LL

Mat identityMat(int n) {
    Mat A(n, Vec(n));
    rep(i, n) A[i][i] = 1;
    return A;
}

Mat multiply(const Mat& A, const Mat& B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    Mat C(n, Vec(m));
    rep(i, n) rep(j, m) rep(k, p) {
        (C[i][j] += A[i][k] * B[k][j]) %= MOD;
    }
    return C;
}

Mat power(const Mat& A, ll n) {
    return n == 0 ? identityMat(A.size()) :
        (n & 1) ? multiply(A, power(A, n-1)) : power(multiply(A, A), n>>1);
}

int toi(char c) {
    return c <= 'Z' ? c-'A'+26 : c-'a';
}

int main() {
    ll n;
    int m, k;
    cin>>n>>m>>k;
    Mat A(m, Vec(m));
    rep(i, m) rep(j, m) A[i][j] = 1;
    rep(i, k) {
        char c, d;
        cin >> c >> d;
        A[toi(c)][toi(d)] = 0;
    }
    Mat v(1, Vec(m, 1));
    v = multiply(v, power(A, n-1));
    ll r = 0;
    rep(i, m) (r += v[0][i]) %= MOD;
    cout << r << endl;
    return 0;
}