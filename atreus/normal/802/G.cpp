#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s.size() < 5)
        return cout << "NO" << endl, 0;
    char c[5] = {'h', 'e', 'i', 'd', 'i'};
    int k = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == c[k])
            k ++;
        if (k >= 5)
            return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
}