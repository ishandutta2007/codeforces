#include <bits/stdc++.h>

using namespace std;

int n;
int a[20];
int sum;

void dfs(int v){
    if (v == n + 1){
        if (sum % 360 == 0){
            cout << "YES" << endl;
            exit(0);
        }
        return;
    }
    sum += a[v];
    dfs(v + 1);
    sum -= a[v];
    sum -= a[v];
    dfs(v + 1);
    sum += a[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    cout << "NO" << endl;
}