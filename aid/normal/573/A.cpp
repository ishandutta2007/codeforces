#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        while(!(a[i] % 2))
            a[i] /= 2;
        while(!(a[i] % 3))
            a[i] /= 3;
    }
    for(int i = 1; i < n; i++)
        if(a[i] != a[0]) {
            cout << "No\n";
            return 0;
        }
    cout << "Yes\n";
    return 0;
}