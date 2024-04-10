#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    long long r = 0;
    long long s = 0;
    vector<char> v(n + 1);
    int m = 0;
    for(int i = 1; i < a.size(); i++) {
        m++;
        r = s - (n - m) * (m - 1) * (long long)a[i];
        s += a[i] * (m - 1);
        if(r < k) {
            s -= a[i] * (m - 1);
            n--;
            m--;
            cout << i << '\n';
        }
    }
}