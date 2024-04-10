#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i){
        cin >> s;
        map < char, int > rt;
        for (auto c : s){
            if (rt.find(c) == rt.end()) rt[c] = 1;
            else rt[c]++;
        }
        if (rt.size() == 1) cout << -1 << endl;
        else{
            for (auto key : rt){
                for (int j = 0; j < key.second; ++j) cout << key.first;
            }
            cout << endl;
        }
    }
    return 0;
}