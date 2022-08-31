#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a[100], counter = 0;
    cin >> n >> k;
    k -= 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if (a[i] >= a[k] && a[i] > 0) {
            counter++;
        }
    }
    cout << counter;
}