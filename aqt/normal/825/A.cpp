#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    string s;
    cin >> N >>  s;
    s = "0" + s + "0";
    queue<int> stk;
    int cnt = 0;
    for(int i = 1; i<=N+1; i++){
        if(s[i] == '0'){
            stk.push(cnt);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    while(stk.size()){
        cout << stk.front();
        stk.pop();
    }
}