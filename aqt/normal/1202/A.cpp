#include <bits/stdc++.h>

using namespace std;

int T;
string s, t;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> s >> t;
        int idx1 = 0, idx2 = 0;
        for(int i= 0; i<t.size(); i++){
            if(t[i] == '1'){
                idx2 = i;
            }
        }
        idx2 = t.size()-1-idx2;
        int cnt = 0;
        for(int i = s.size()-idx2-1; i>0; i--){
            if(s[i] == '1'){
                break;
            }
            else{
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}