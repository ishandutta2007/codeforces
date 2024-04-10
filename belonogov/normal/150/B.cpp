#include <iostream>
#include <cstdio>

using namespace std;
const long long p = 1e9 + 7;

long long step(long long k, long long a){
    long long res = 1;
    int i;
    for (i = 1; i <= k; i++)
        res = (res * a) % p;
    return res;
}

int main()
{
   long long n, m, k;
    cin >> n >> m >> k;
    if (k > n || k == 1){
        cout << step(n, m);
        return 0;
    }
    if (k == n){
        cout << step((n + 1) / 2, m);
        return 0;
    }
    if (k % 2 == 1){
        cout << step(2, m);
        return 0;
    }
    if (k % 2 == 0){
        cout << m;
        return 0;
    }
    return 0;
}