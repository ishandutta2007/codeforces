#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort (b, b + n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != b[i])
            ans ++;
    }
    if (ans <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}