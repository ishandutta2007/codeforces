#include <bits/stdc++.h>

using namespace std;

int isi[400005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map < char, vector < int>  > d;
    for (int i = 0; i < 26; ++i){
        vector < int > prom;
        d[char('a' + i)] = prom;
    }
    for (int i = 0; i < n; ++i){
        d[s[i]].push_back(i);
    }
    for (int i = 0; i < 26; ++i){
        int k1 = k;
        for (int z = 0; z < min((int)d[char('a' + i)].size(), k1); ++z){
            isi[d[char('a' + i)][z]] = 1;
            k--;
        }
    }
    for (int i = 0; i < n; ++i){
        if (isi[i] == 0)
            cout << s[i] << "";
    }
    return 0;
}