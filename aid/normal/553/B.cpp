#include <iostream>

using namespace std;

const int MAXN = 55;
long long fib[MAXN];

void gen(int pos, int n, long long k) {
    if(pos == n) {
        cout << '\n';
        return;
    }
    if(k < fib[n - pos - 1]) {
        cout << pos + 1 << ' ';
        gen(pos + 1, n, k);
    }
    else {
        k -= fib[n - pos - 1];
        cout << pos + 2 << ' ' << pos + 1 << ' ';
        gen(pos + 2, n, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < MAXN; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int n;
    long long k;
    cin >> n >> k;
    k--;
    gen(0, n, k);
    return 0;
}