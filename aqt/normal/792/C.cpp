#include <bits/stdc++.h>

using namespace std;

string s;
queue<char> qu[2];

void solve(int idx1, int idx2, int t){
    for(int i = 0; i<s.size(); i++){
        if(i != idx1 && i != idx2){
            qu[t].push(s[i]);
        }
    }
    while(qu[t].size() > 1 && qu[t].front() == '0'){
        qu[t].pop();
    }
}

void out(int t){
    while(qu[t].size()){
        cout << qu[t].front();
        qu[t].pop();
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int sum = 0;
    for(char c : s){
        sum += c-'0';
    }
    sum %= 3;
    if(sum == 0){
        cout << s << endl;
        return 0;
    }
    if(sum == 1){
        int idx1 = -1, idx2 = -1, idx3 = -1;
        for(int i = s.size()-1; i>=0; i--){
            if((s[i]-'0')%3 == 1){
                if(idx3 == -1){
                    idx3 = i;
                }
            }
            if((s[i]-'0')%3 == 2){
                if(idx2 == -1){
                    idx2 = i;
                }
                else if(idx1 == -1){
                    idx1 = i;
                }
            }
        }
        if(idx1 != -1){
            solve(idx2, idx1, 1);
        }
        if(idx3 != -1){
            solve(idx3, -1, 0);
        }
        if(idx1 ==idx3){
            cout << -1 << endl;
            return 0;
        }
    }
    else{
        int idx1 = -1, idx2 = -1, idx3 = -1;
        for(int i = s.size()-1; i>=0; i--){
            if((s[i]-'0')%3 == 2){
                if(idx3 == -1){
                    idx3 = i;
                }
            }
            if((s[i]-'0')%3 == 1){
                if(idx2 == -1){
                    idx2 = i;
                }
                else if(idx1 == -1){
                    idx1 = i;
                }
            }
        }
        if(idx1 != -1){
            solve(idx2, idx1, 1);
        }
        if(idx3 != -1){
            solve(idx3, -1, 0);
        }
        if(idx1 ==idx3){
            cout << -1 << endl;
            return 0;
        }
    }
    if(qu[0].empty()){
        if(qu[1].empty()){
            cout << -1 << endl;
            return 0;
        }
        out(1);
    }
    else if(qu[1].empty()){
        out(0);
    }
    else if(qu[0].size() > qu[1].size()){
        out(0);
    }
    else{
        out(1);
    }
}