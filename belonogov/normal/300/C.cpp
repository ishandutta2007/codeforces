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

const int maxn = 1000010;
const int inf = 1e9;
const int mod = 1e9 + 7;

long long ans = 0;

bool flag[maxn];

int pow1(long long x, int b){
    long long res = 1;
    for (; b > 0; b /= 2, x = (x * x) % mod)
        if (b % 2 == 1)
            res = (res * x) % mod;
    return res;
}


void Cnk(int n){
    long long res = 1;
//  for(int i = 0; i < n + 1; i++)
//      cerr << flag[i] << " ";
//  cerr << endl;
    for (int i = 0; i < n + 1; i++){
        if (flag[i]) 
            ans = (ans + res) % mod;
        res = (res * (n - i)) % mod;
        res = (res * pow1(i + 1, mod - 2)) % mod;       
//      epr("res %d\n", (int)res);
        
    }
/*
    for (int i = k + 1; i <= n; i++)
        res = (res * i) % mod;
    for (int i = 1; i <= n - k; i++)
        res = (res * pow1(i, mod - 2)) % mod;
    ans = (ans + res) % mod;    */
}


int main(){
//     freopen("in", "r", stdin);       
//     freopen("out", "w", stdout);
    int a, b, n, d;
    scanf("%d%d%d", &a, &b, &n);
    int sum = 0;
    sum = a * n;
    for (int i = 0; i < n + 1; i++){
        d = sum;
        flag[i] = 1;
        for(;d > 0; d /= 10)
            if (d % 10 != a && d % 10 != b)
                flag[i] = 0;
        
        sum = sum - a + b;
    }
    Cnk(n);
        
 
    cout << ans << endl;
    return 0;
}