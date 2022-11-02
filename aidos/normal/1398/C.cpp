#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> s;
        int sum = 0;
        map<int, int> m;
        m[0]++;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            sum += s[i] - '0';
            int cur = sum - i - 1;
            ans += m[cur];
            m[cur]++;
        }
        cout << ans << "\n";
    }
}