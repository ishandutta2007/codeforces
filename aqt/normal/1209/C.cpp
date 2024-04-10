#include <bits/stdc++.h>

using namespace std;

string s;
int ans[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >>N >> s;
        bool p = 0;
        for(int d = 0; d<10; d++){
            int s1 = 0, s2 = d;
            bool b = 1;
            for(int i = 0; i<N; i++){
                if(s2 <= s[i]-'0'){
                    ans[i] = 2;
                    s2 = s[i]-'0';
                }
                else if(s1 <= s[i]-'0' && s[i]-'0' <= d){
                    ans[i] = 1;
                    s1 = s[i]-'0';
                }
                else{
                    b = 0;
                    break;
                }
            }
            if(b){
                p = 1;
                break;
            }
        }
        if(!p){
            cout << "-" << "\n";
        }
        else{
            for(int i =0; i<N; i++){
                cout << ans[i];
            }
            cout << "\n";
        }
    }
}