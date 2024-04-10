#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pi pair<int,int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> cnt(26);
        for(char c : s) {
            cnt[c-'a']++;
        }
        int i = 0;
        for(; i < n; i ++) {
            if(cnt[s[i]-'a'] > 1) {
                cnt[s[i]-'a']--;
            } else {
                break;
            }
        }
        for(int j = i; j < n; j ++) {
            cout << s[j];
        }
        cout << "\n";
    }
    return 0;
}