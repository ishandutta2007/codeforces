#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e4 + 10;
const long long inf = 1e15;

long long a[maxn];
long long r, p, fi_p;
int k;
    

long long gcd(long long a, long long b){
    return (b == 0) ? a : gcd(b, a % b);    
}

long long mul(long long a, long long b, long long mod){
    long long res = 0;
    for (; b > 0; b /= 2, a = (a + a) % mod)
        if (b % 2 == 1)
            res = (res + a) % mod;          
    return res; 
}

long long pow1(long long x, long long k, long long mod){
    long long res = 1;
    for (; k > 0; k /= 2, x = mul(x, x, mod))
        if (k % 2 == 1)
            res = mul(res, x, mod);
    return res;
}

long long fi(long long n){
    long long d = n;
    for (long long i = 2; i * i <= d; i++){
        bool flag = 0;
        for (; d % i == 0; d /= i, flag = 1);
        if (flag)
            n -= n / i;     
    }
    if (d > 1)
        n -= n / d;
    return n;   
}



void solve(long long st){
    long long a1, a2, r1, r2;
    bool flag = 1;
//  cerr << "st : " << st << endl;
    for (int j = 0; flag && j < k; j++){
        if (a[j] % st == 0){
            if (p == -1){
                p = st; 
                r = st - j;                     
            }
            else{
                r1 = r;
                a1 = p;
                r2 = st - j;
                a2 = st;
//              epr("a1 r1   a2 r2  %lld %lld  %lld %lld\n", a1, r1, a2, r2); 
                p = a1 * a2;
//              r = (r1 * a2 * pow1(a2, fi(a1) - 1, a1) + r2 * a1 * pow1(a1, fi(a2) - 1, a2)) % p;
                r = (mul(mul(r1, a2, p), pow1(a2, fi(a1) - 1, a1), p)
                    + mul(mul(r2, a1, p), pow1(a1, fi(a2) - 1, a2), p)) % p;

                //              cerr << r2 * a1 * pow1(a1, a2 - 2, a2) << endl;
            }

            flag = 0;
        }
    }
    assert(!flag);
}
int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long n, m, lcm,  d, st;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    lcm = 1;
    for (int i = 0; i < k; i++){
        d = gcd(lcm, a[i]);
//      cerr << "a[i] gcd " << a[i] << " " << d << "           ";
        if (lcm / d * 1.0 * a[i] > inf){
            printf("NO\n");
            return 0;
        }
        lcm = lcm / d * a[i];
//      cerr << lcm << endl;
    }
//  cerr << "lcm : " << lcm << endl;
    if (lcm > n){
        printf("NO\n");
        return 0;           
    }
    d = lcm;
    p = -1;
    for (long long i = 2; i * i <= d; i++){
        for (st = 1; d % i == 0; d /= i, st *= i);
        if (st > 1){
            solve(st);  
//          cerr << "r p " << r << " " << p << endl;        
        }
    }
    if (d > 1)
        solve(d);
    r = (r == 0)? p: r;
    cerr << "r p " << r << " " << p << endl;
    if (r + k - 1 > m){
        printf("NO\n");
        return 0;       
    }
    for (int i = 0; i < k; i++)
        if (gcd(r + i, lcm) != a[i]){
            printf("NO\n");
            return 0;           
        }
    printf("YES\n");
 
    return 0;
}