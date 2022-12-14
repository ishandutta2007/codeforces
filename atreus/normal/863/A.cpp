#include <bits/stdc++.h>

using namespace std;

bool ispalindrome(string s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string a;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0')
            a += '0';
        else
            break;
    }
    a += s;
    if (ispalindrome(a))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}