#include <bits/stdc++.h>

using namespace std;

int b[200000];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        sum += a;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort (b, b + n);
    if (b[n - 1] + b[n - 2] >= sum)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}