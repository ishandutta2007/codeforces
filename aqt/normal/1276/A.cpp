#include <bits/stdc++.h>

using namespace std;

int T;
string s;

bool match(int idx, string k){
    for(int i = 0; i<k.size(); i++){
        if(s[i+idx] != k[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> s;
        int N = s.size();
        s.push_back('&'), s.push_back('&'), s.push_back('&'), s.push_back('&');
        vector<int> ans;
        for(int i = 0; i<N; i++){
            if(match(i, "twone")){
                ans.push_back(i+2);
                s[i+2] = ' ';
            }
        }
        for(int i = 0; i<N; i++){
            if(match(i, "one")){
                ans.push_back(i+1);
                s[i+1] = ' ';
            }
            if(match(i, "two")){
                s[i+1] = ' ';
                ans.push_back(i+1);
            }
        }
        cout << ans.size() << "\n";
        for(int n : ans){
            cout << n+1 << " ";
        }
        cout << "\n";
    }
}