#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int a0 = 0, a1 = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++){
        a0 = abs((s1[i] - '0') - (s2[i] - '0')) ;
        a1 = 10 - abs((s1[i] - '0') - (s2[i] - '0'));
        ans += min(a0, a1);
    }
    cout << ans;

}