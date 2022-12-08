#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int n = str.size();
        vector<vector<int>> pos(26);
        for(int i = n - 1; i >= 0; i --) {
            pos[str[i]-97].push_back(i);
        }
        vector<bool> none(26);
        for(int i = 0; i < 26; i ++) {
            none[i] = pos[i].empty();
        }
        vector<bool> chosen(n);
        vector<bool> used(26);
        // cout << "hi" << endl;
        for(int iii = 25; iii >= 0; iii --) {
            for(int i = 25; i >= 0; i --) {
                if(used[i] || none[i]) {continue;}
                int mn = 1000000;
                for(int j = 0; j < 26; j ++) {
                    if(used[j] || none[j] || j == i) {
                        continue;
                    }
                    mn = min(mn,pos[j][0]);
                }
                // cout << "lol" << endl;
                if(pos[i][pos[i].size()-1] < mn) {
                    // cout << (char)(i+97) << endl;
                    int idx = pos[i][pos[i].size()-1];
                    chosen[pos[i][pos[i].size()-1]] = true;
                    used[i] = true;
                    // cout << "yes? "<< endl;
                    for(int j = 0; j < 26; j ++) {
                        if(used[j] || none[j]) { continue; }
                        while(pos[j][pos[j].size()-1] < idx) {
                            pos[j].pop_back();
                        }
                    }
                    break;
                }
            }
        }
        for(int i = 0; i < n; i ++) {
            if(chosen[i]) {
                cout << str[i];
            }
        }
        cout << "\n";
    }
    
    return 0;
}