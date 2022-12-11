#include <bits/stdc++.h>

using namespace std;

int fre[30], tot[30];
stack<int> stk;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '?'){
            stk.push(i);
            continue;
        }
        tot[s[i]-'a']++;
    }
    for(int j = 0; j<t.size(); j++){
        fre[t[j]-'a']++;
    }
    while(stk.size()){
        for(int i = 0; i<26; i++){
            tot[i] -= fre[i];
            while(tot[i] < 0 && stk.size()){
                s[stk.top()] = (char) (i+'a');
                stk.pop();
                tot[i]++;
            }
        }
    }
    cout << s << endl;
}