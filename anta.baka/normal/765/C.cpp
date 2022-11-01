#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    long long k, a, b;
    cin >> k >> a >> b;
    long long c1 = a / k;
    long long c2 = b / k;
    if(c1 + c2 == 0 || a % k && c2 == 0 || b % k && c1 == 0)
        return cout << -1, 0;
    cout << c1 + c2;
}