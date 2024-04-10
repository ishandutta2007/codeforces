#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    k = n - k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    nth_element(a, a + k, a + n);
    cout << a[k] << '\n';
    return 0;
}