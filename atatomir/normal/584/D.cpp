#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxDim 100011
#define limit 100000

int n, i;
bool ciur[maxDim];
vector<int> pr;

void result(int v,int a,int b,int c) {
    printf("%d\n",v);
    if (v > 0) printf("%d ", a);
    if (v > 1) printf("%d ", b);
    if (v > 2) printf("%d ", c);

    exit(0);
}

void preprocess() {
    ciur[1] = true;
    for (long long i = 2; i <= limit; i++) {
        if (ciur[i]) continue;

        pr.pb(i);
        for (long long j = i * i; j <= limit; j += i) ciur[j] = true;
    }
}

bool isPrime(int v) {
    if (v <= limit) return !ciur[v];

    int go = (int)sqrt(v);
    for (auto who : pr) {
        if (who > go) break;
        if (v % who == 0)
            return false;
    }

    return true;
}

int main()
{
    //freopen("*.in","r",stdin);

    scanf("%d", &n);

    if (n == 3) result(1, 3, 0, 0);
    if (n == 5) result(1, 5, 0, 0);

    preprocess();

    n -= 3;

    if (isPrime(n - 2)) result(3, 3, 2, n - 2);
    for (i = n - 1; i > 1; i -= 2) {
        if (isPrime(i)) {
            if (isPrime(n - i)) {
                result(3, 3, i, n - i);
            }
        }
    }

    return 0;
}