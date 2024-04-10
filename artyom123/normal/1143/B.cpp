#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    vector <long long> a(s.size());
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    long long now = 1;
    long long ans = 0;
    long long u = 1;
    if (a.size() > 1) {
        for (int i = 0; i < a.size() - 1; i++) {
            u *= 9;
        }
        ans = max(ans, u);
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            long long p = 1;
            for (int j = i + 1; j < a.size(); j++) {
                p *= 9;
            }
            ans = max(ans, now * (a[i] - 1) * p);
        }
        now *= a[i];
        if (i == a.size() - 1) {
            ans = max(ans, now);
        }
    }
    cout << ans;
    return 0;
}