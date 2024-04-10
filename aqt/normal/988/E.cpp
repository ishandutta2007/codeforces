#include <bits/stdc++.h>

using namespace std;

string s;

int chk(char a, char b, int i){
    int tot = 0;
    string t = s;
    for(int j = i; j<t.size()-1; j++){
        swap(t[j], t[j+1]);
        tot++;
    }
    int mini = INT_MAX/2;
    for(int j = 0; j<t.size()-1; j++){
        if(t[j] == a || t[j] == b){
            string u = t;
            int cnt = 0;
            for(int k = j; k<t.size()-2; k++){
                swap(u[k], u[k+1]);
                cnt++;
            }
            if(u[0] == '0'){
                bool p = 0;
                for(int k = 0; k<t.size()-2; k++){
                    if(u[k] != '0'){
                        cnt += k;
                        p = 1;
                        break;
                    }
                }
                if(!p){
                    cnt = INT_MAX/2;
                }
            }
            mini = min(cnt, mini);
        }
    }
    tot += mini;
    return tot;
}

int main(){
    cin >> s;
    int ans = INT_MAX;
    for(int i =0; i<s.size(); i++){
        if(s[i] == '0'){
            ans = min(ans, chk('0', '5', i));
        }
        else if(s[i] == '5'){
            ans = min(ans, chk('2', '7', i));
        }
    }
    if(ans > 1000){
        ans = -1;
    }
    cout << ans << endl;
}