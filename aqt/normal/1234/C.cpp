#include <bits/stdc++.h>

using namespace std;

int Q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        vector<int> top, bot;
        string s;
        cin >> s;
        for(int i = 1; i<=N; i++){
            int k;
            k = s[i-1]-'0';
            top.push_back(k);
        }
        cin >> s;
        for(int i = 1; i<=N; i++){
            int k;
            k = s[i-1]-'0';
            bot.push_back(k);
        }
        int r = 1;
        bool p = 1;
        for(int n = 0; n<N; n++){
            if(r == 1){
                if(top[n] > 2){
                    if(bot[n] > 2){
                        r = 0;
                    }
                    else{
                        p = 0;
                    }
                }
            }
            else{
                if(bot[n] > 2){
                    if(top[n] > 2){
                        r = 1;
                    }
                    else{
                        p = 0;
                    }
                }
            }
        }
        p &= r==0;
        if(p){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}