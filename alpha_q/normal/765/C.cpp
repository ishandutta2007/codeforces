#include <bits/stdc++.h> 

using namespace std;

int k, a, b;

int main (int argc, char const *argv[]) {
    cin >> k >> a >> b;
    if (a > b) swap(a, b);
    if (b < k) {
        puts("-1");
        return 0;
    }
    if (a >= k) {
        printf("%d\n", a/k + b/k);
        return 0;
    }
    if (b % k) {
        puts("-1");
        return 0;
    }
    printf("%d\n", b/k);
    return 0;
}