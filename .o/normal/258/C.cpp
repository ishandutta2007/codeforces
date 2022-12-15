//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

typedef long long int64;
typedef long double ld;

const int64 MAXN = 500005;
const int64 MOD = 1000 * 1000 * 1000 + 7;

int64 a[MAXN], f[MAXN], f_time[MAXN], ANS;
vector<int64> v[MAXN];

#define pb push_back

void filling(int64 n) {   //CORRECT
    for (int64 i = 1; i <= a[n - 1]; ++i)
        for (int64 j = i; j <= a[n - 1]; j += i)
            v[j].push_back(i);
}

/*int64 BS(int64 left, int64 right, int64 key) {       // CORRECT
    if (left == right)
        return left;
    else if (right - 1 == left) {
        if (a[left] >= key)
            return left;
        return right;
    }
    int64 mid = (left + right) / 2;
    if (a[mid] >= key)
        return BS(left, mid, key);
    return BS(mid + 1, right, key);
}*/

int64 pow(int64 x, int64 y) {   // x ^ y        CORRECT
    if (!y)
        return 1;
    else if (y == 1)
        return x % MOD;
    if (y % 2) {
        int64 z = pow(x, y / 2) % MOD;
        return (z * ((z * x) % MOD)) % MOD;
    }
    int64 z = pow(x, y / 2) % MOD;
    return (z * z) % MOD;
}

int64 RMN(int64 e) {
    if (e >= 0)
        return e % MOD;
    while (e < 0)
        e += MOD;
    return e;
}

void fill_array(int64 m, int64 n) {
    int64 flag = 0, CC = 1, r;
    if(f_time[flag] != m) f_time[flag] = m, f[flag] = 0;
    
    for (int64 i = 0; i < (int64)v[m].size(); ++i) {
        if (v[m][i] > a[n - 1])
            break;
            
        r = lower_bound(a, a + n, v[m][i]) - a;
        
        if(f_time[r] != m) f_time[r] = m, f[r] = 0;
        ++f[r];
        
        if (r != flag) {
            f[r] += f[flag];
            CC = ((CC % MOD) * (pow(f[flag], r - flag) % MOD)) % MOD;
        }       
        flag = r;
    }
    if(f_time[0] != m) f_time[0] = m, f[0] = 0;
    if (!f[0])
        CC = 0;
    CC %= MOD;
    int64 CP = CC;
    CC = ((CC % MOD) * (pow(f[r], n - r) % MOD)) % MOD;
    CP = ((CP % MOD) * (pow(f[r] - 1, n - r) % MOD)) % MOD;
    CC -= CP;
    CC = RMN(CC);
    ANS = ((ANS % MOD) + (CC % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    int64 n;
    cin >> n;
    for (int64 i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    filling(n);
    for (int64 m = 1; m <= a[n - 1]; ++m) {
        fill_array(m, n);
    }
    cout << ANS << endl;
    cerr << clock() << endl;
    return 0;
}