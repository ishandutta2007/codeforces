#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    vector <int> cnt(26);
    for (int i = 0; i < (int) s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += (cnt[i] & 1);
    }
    cout << (!count || count & 1 ? "First" : "Second") << endl;
}