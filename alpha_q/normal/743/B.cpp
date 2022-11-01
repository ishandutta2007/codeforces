#include <bits/stdc++.h>

using namespace std;

int n; long long k;

int f (int n, long long k) {
    if (n == 1) return 1;
    long long mid = 1LL << (n - 1);
    if (k == mid) return n; 
    if (k < mid) return f(n - 1, k);
    return f(n - 1, k - mid);
}

int main (int argc, char const *argv[]) {
    scanf("%d %lld", &n, &k);
    printf("%d\n", f(n, k));
    return 0;
}