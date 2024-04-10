#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    //cout << s << endl;
    for (int i = 0; i < (int)s.size() / 2; ++i){
        if (s[i] != s[(int)s.size() - 1 - i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    set < char > use;
    for (auto c : s) use.insert(c);
    if (use.size() == 1){
        cout << "Impossible" << '\n';
        return 0;
    }
    int n = s.size();
    for (int i = 0; i < n - 1; ++i){
        string one = "", two = "";
        for (int j = 0; j < n; ++j){
            if (j <= i) one += s[j];
            else two += s[j];
        }
        if (two + one != s && check(two + one)){
            cout << 1 << '\n';
            return 0;
        }
    }
    //cout << 112 << endl;
    if (n % 2 == 1){
        bool f = true;
        for (int i = 0; i < n / 2 - 1; ++i) if (s[i] != s[i + 1]) f = false;
        if (f){
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    string pref = "";
    for (int i = 0; i < n / 2; ++i) pref += s[i];
    if (check(pref)){
        cout << 2 << '\n';
    }
    else{
        cout << n % 2 + 1 << '\n';
    }
    return 0;
}