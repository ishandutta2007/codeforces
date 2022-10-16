#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if(a[n - 1] == 1) {
        for(int i = 0; i < n - 1; i++)
            cout << a[i] << ' ';
        cout << 2 << ' ';
        cout << '\n';
        return 0;
    }
    cout << 1 << ' ';
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}