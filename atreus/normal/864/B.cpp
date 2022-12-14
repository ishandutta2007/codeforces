#include <bits/stdc++.h>

using namespace std;

vector <char> ans;

int main(){
    int n, jav = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] - 'A' > 26){
            bool cur = false;
            for (int j = 0; ans.size() > 0 && j < ans.size(); j++){
                if (ans[j] == s[i]){
                    cur = true;
                    break;
                }
            }
            if (cur == false)
                ans.push_back(s[i]);
        }
        if (s[i] - 'A' <= 26){
            int k = ans.size();
            jav = max(jav, k);
            ans.clear();
        }
    }
    int k = ans.size();
    jav = max(jav, k);
    cout << jav << endl;
}