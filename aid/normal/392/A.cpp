#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    long long ans = 0, up = n;
    for(long long i = 1; i <= n; i++) {
        int k = 0;
        while(i * i + up * up > n * n) {
            k++;
            up--;
        }
        if(!k)
            k++;
        ans += k;
    }
    cout << (n? 4 * ans : 1) << '\n';
    return 0;
}