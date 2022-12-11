#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N, A, B;
        cin >> N >> A >> B >> s;
        int K = 2*A/B;
        long long ans = 1LL*A*N + 1LL*B*(N+1);
        bool start =1 ;
        int cnt = 1;
        for(int i = 1; i<s.size(); i++){
            if(s[i] == '1'){
                if(cnt){
                    if(start){
                        start = 0;
                    }
                    else{
                        if(1LL*2*A+B <= 1LL*(cnt)*B){
                            ans += 1LL*2*A+B;
                        }
                        else{
                            ans += 1LL*(cnt)*B;
                        }
                    }
                    cnt = 0;
                }
                ans += B;
            }
            if(s[i] == '0'){
                cnt++;
            }
        }
        if(!start){
            ans += 2*A+B;
        }
        cout << ans << "\n";
    }
}