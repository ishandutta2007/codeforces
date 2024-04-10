#include <bits/stdc++.h>

using namespace std;

map < char, vector < int > > T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int kol = 1;
    for (int i = 1; i < n; ++i){
        if (s[i] == s[i - 1]){
            kol++;
            continue;
        }
        T[s[i - 1]].push_back(kol);
        kol = 1;
    }
    T[s.back()].push_back(kol);
    int ans = 0;
    for (auto key : T){
        int tt = 0;
        for (auto tr : key.second) tt += tr / k;
        ans = max(ans, tt);
    }
    cout << ans << '\n';
    return 0;
}