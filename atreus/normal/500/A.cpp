#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e4 + 1000;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    int ans = 1;
    while (ans < t){
        ans += a[ans];
    }
    if (ans == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}