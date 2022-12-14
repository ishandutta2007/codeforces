#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    for (int i = n - 1; i >= 1; i--){
        int x = a[i] / (__gcd(a[i], a[i - 1]));
        while (x % 2 == 0)
            x /= 2;
        while (x % 3 == 0)
            x /= 3;
        if (x > 1){
            cout << "No" << endl;
            return 0;
        }
        int y = a[i] / (__gcd(a[i], a[min(i + 1, n - 1)]));
        while (y % 2 == 0)
            y /= 2;
        while (y % 3 == 0)
            y /= 3;
        if (y > 1){
            cout << "No" << endl;
            return 0;
        }
    }
    int x = a[0] / (__gcd(a[0], a[1]));
    while (x % 2 == 0)
        x /= 2;
    while (x % 3 == 0)
        x /= 3;
    if (x > 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}