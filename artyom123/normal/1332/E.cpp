#include<bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
 
const long long mod = 998244353;
 
struct matrix{
    int n;
    vector <vector<long long>> m;
    matrix(){}
    matrix(vector <vector<long long>> _m) {
        m = _m;
        n = m.size();
    }
    matrix operator* (const matrix &a) const {
        vector <vector<long long>> res(n, vector <long long> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long now = 0;
                for (int k = 0; k < n; k++) {
                    now += m[i][k] * a.m[k][j];
                    now %= mod;
                }
                res[i][j] = now;
            }
        }
        return res;
    }
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};
 
matrix my_pow(matrix n, long long m) {
    if (m == 1) {
        return n;
    }
    if (m % 2 == 0) {
        matrix res = my_pow(n, m / 2);
        return res * res;
    }
    m--;
    matrix res = my_pow(n, m);
    return res * n;
}
 
long long total = 0;
 
long long bin_pow(long long n, long long m) {
    if (m == 1) {
        return n;
    }
    long long res = bin_pow(n, m / 2);
    if (m % 2 == 0) {
        return (res * res) % mod;
    }
    return (((res * res) % mod) * n) % mod;
}
 
int main() {
    long long n, m, l, r;
    cin >> n >> m >> l >> r;
    if ((n * m) % 2 == 1) {
        total = bin_pow(r - l + 1, n * m);
        cout << total;
        return 0;
    }
    long long cntn = 0, cntc = 0;
    cntc = r / 2 - (l - 1) / 2;
    cntn = (r - l + 1) - cntc;
    cntn %= mod;
    cntc %= mod;
    vector <vector<long long>> ma(2, vector<long long>(2));
    ma[0][0] = cntc;
    ma[0][1] = cntn;
    ma[1][0] = cntn;
    ma[1][1] = cntc;
    matrix my(ma);
    my = my_pow(my, n * m - 1);
    cout << (my.m[0][0] * cntc + my.m[1][0] * cntn) % mod;
    return 0;
}