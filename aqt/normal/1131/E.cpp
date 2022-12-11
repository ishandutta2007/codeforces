#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int cons[30], crnt[30];
int ans = 0;

void build(){
    int cnt = 1;
    fill(crnt, crnt+26, 0);
    crnt[s[0]-'a']++;
    for(int i = 1; i<s.size(); i++){
        if(s[i] != s[i-1]){
            cnt = 1;
        }
        else{
            cnt++;
        }
        crnt[s[i]-'a'] = max(crnt[s[i]-'a'], cnt);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    N--;
    cin >> s;
    build();
    for(int i = 0; i<26; i++){
        cons[i] = crnt[i];
    }
    while(N--){
        cin >> s;
        build();
        int pre = 0;
        for(int i= 0; i<s.size(); i++){
            if(s[i] != s[0]){
                break;
            }
            pre++;
        }
        if(pre == s.size()){
            for(int i =0; i<26; i++){
                if((int)(s[0]-'a') == i){
                    cons[i] = (cons[s[0]-'a']+1)*(pre)+cons[s[0]-'a'];
                }
                else if(cons[i]){
                    cons[i] = 1;
                }
            }
        }
        else{
            int suf = 0;
            for(int i =s.size()-1; i>=0; i--){
                if(s[i] != s[s.size()-1]){
                    break;
                }
                suf++;
            }
            if(s[s.size()-1] == s[0]){
                for(int i =0; i<26; i++){
                    if((int)(s[0]-'a') == i){
                        cons[i] = (cons[i] > 0) + pre + suf;
                    }
                    else if(cons[i]){
                        cons[i] = 1;
                    }
                }
            }
            else{
                bool bpre = 0, bsuf = 0;
                if(cons[s[s.size()-1]-'a'] > 0){
                    bsuf = 1;
                }
                if(cons[s[0]-'a'] > 0){
                    bpre = 1;
                }
                for(int i = 0; i<26; i++){
                    if(crnt[i]){
                        cons[i] = crnt[i];
                    }
                    else if(cons[i]){
                        cons[i] = 1;
                    }
                }
                cons[s[0]-'a']+=bpre;
                cons[s[s.size()-1]-'a']+=bsuf;
            }
        }
    }
    ans = 0;
    for(int i = 0; i<26; i++){
        ans = max(ans, cons[i]);
    }
    cout << ans << endl;
}