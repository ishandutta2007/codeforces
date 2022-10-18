#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()){
        cout << "No" << '\n';
        return 0;
    }
    vector < char > T = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < (int)s.size(); ++i){
        bool f = false;
        bool f1 = false;
        for (auto c : T){
            if (s[i] == c) f = true;
            if (t[i] == c) f1 = true;
        }
        if (f != f1){
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}