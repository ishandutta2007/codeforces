#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = s.size()-1; i>=0; i--){
        if(s[i] == '0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
        if(cnt1 > cnt0){
            cnt0++;
            s[i] = '0';
        }
    }
    cout << s << endl;
}