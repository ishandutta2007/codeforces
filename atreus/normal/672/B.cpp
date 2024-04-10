#include <bits/stdc++.h>

using namespace std;

int num[30];

int main() {
	ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    if (n > 26){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
        num[s[i] - 'a'] ++;
    int ans = 0;
    for (int i = 0; i < 26; i++){
        if (num[i] == 0)
            continue;
        ans += num[i] - 1;
    }
    cout << ans << endl;
}