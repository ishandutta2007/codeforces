#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, tmp, counter;
    string s;
    tmp = counter = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        tmp = 0;
        for (int j = 0; j < s.length(); j++) {
            if(s[j] == '4' || s[j] == '7') tmp++;
        }
        if(tmp <= k){
            counter++;
        }
    }
    cout << counter;
}