#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; int a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    map<int, int> mem;
    for(int i = 0; i < n; i++) mem[b[i]] = i;
    for(int i = 0; i < n; i++)
        if(mem[a[i]] == n - 1) cout << b[0] << ' ';
        else cout << b[mem[a[i]] + 1] << ' ';
}