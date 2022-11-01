#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        int cnt = 1, cst = 0;
        while(cst + cnt <= n) cst += cnt, cnt++;
        while(cnt--) cout << ch;
        n -= cst;
    }
}