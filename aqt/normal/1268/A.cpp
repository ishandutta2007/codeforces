#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;

bool solve(){
    bool carry = 0;
    for(int i = s.size()-1; i>=K; i--){
        if((int) (s[i]+carry) <= (int) (s[i%K])){
            carry = 0;
        }
        else{
            carry = 1;
        }
    }
    if(carry){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> s;
    while(!solve()){
        bool carry = 1;
        for(int i = K-1; i>=0; i--){
            if(s[i] == '9'){
                carry = 1;
                s[i] = '0';
            }
            else{
                carry = 0;
                s[i]++;
                break;
            }
        }
        if(carry){
            s = "1" + s;
        }
        for(int i = K; i<s.size(); i++){
            s[i] = '0';
        }
    }
    cout << s.size() << "\n";
    for(int i = 0; i<s.size(); i++){
        cout << s[i%K];
    }
}