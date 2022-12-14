#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 500;
int v[maxn];

int main() {
	ios_base::sync_with_stdio(false);
    string s;
    int k, mxn = 0;
    cin >> s >> k;
    for (int i = 0; i < 26; i++){
        cin >> v[i];
        mxn = max(mxn, v[i]);
    }
    long long ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += (i + 1) * v[s[i] - 'a'];
    for (int i = s.size() + 1; i <= s.size() + k; i++)
        ans += i * mxn;
    cout << ans << endl;
}