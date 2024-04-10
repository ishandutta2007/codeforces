#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> s;
        string t;
        for(char c: s) {
            if(t.size() > 0 && t.back() == c) t.pop_back();
            t += c;
        }
        set<char> S (t.begin(), t.end());
        if(S.size() != t.size()) {
            cout << "NO\n";
        } else {
            cout << "yEs\n";
        }
    }
}