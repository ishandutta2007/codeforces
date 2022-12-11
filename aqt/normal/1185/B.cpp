#include <bits/stdc++.h>

using namespace std;

string s, t;

bool chk(){
    if(t.size() < s.size()){
        return false;
    }
    int j = -1;
    for(int i = 0; i<t.size(); i++){
        if(j != s.size()-1 && s[j+1] == t[i]){
            j++;
        }
        else if(j == -1 || t[i] != s[j]){
            return false;
        }
    }
    return j == s.size()-1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> s >> t;
        if(chk()){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}