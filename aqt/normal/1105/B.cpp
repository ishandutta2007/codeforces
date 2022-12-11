#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    int N, K;
    cin >> N >> K >> s;
    int ans = 0;
    for(char c = 'a'; c<='z'; c++){
        int cnt = 0, crnt = 0;
        for(int i = 0; i<N; i++){
            if(s[i] == c){
                cnt++;
                if(cnt == K){
                    cnt = 0;
                    crnt++;
                }
            }
            else{
                cnt = 0;
            }
        }
        ans = max(crnt, ans);
    }
    cout << ans << endl;
}