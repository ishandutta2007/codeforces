#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 500;
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] == a[n - 1]){
        cout << 0 << " " << 1ll * n * (n - 1) / 2;
        return 0;
    }
    cout << a[n - 1] - a[0] << " ";
    int k = 1, l = 1;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1])
            k ++;
        else
            break;
    }
    for (int i = n - 2; i >= 0; i--){
        if (a[i] == a[i + 1])
            l ++;
        else
            break;
        }
    cout << 1ll * l * k << endl;
}