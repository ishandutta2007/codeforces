#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int k, cnt = 0;
    cin >> k;
    int n = s.length();
    if (n < k)
        return cout << "impossible" << endl, 0;
    for (int i = 0; i < n - 1; i++){
        if (s[i] != '0'){
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j]){
                    s[j] = '0';
                    cnt++;
                }
            }
        }
    }
    if (n - cnt >= k)
        return cout << 0 << endl, 0;
    cout << k - (n - cnt);
}