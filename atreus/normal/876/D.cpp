#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 500;
int a[maxn];
bool mark[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << 1 << " ";
    int poi = n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mark[a[i]] = true;
        while (mark[poi] == true)
            poi --;
        cout << i - (n - poi) + 1 << " ";
    }
}