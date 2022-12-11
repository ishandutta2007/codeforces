#include <bits/stdc++.h>

using namespace std;

int Q, N;
string s, t;
int cnt[2][26];

int main(){
    cin >> Q;
    while(Q--){
        cin >> N >> s >> t;
        int mx = 0;
        for(int i = 0; i<26; i++){
            cnt[0][i] = cnt[1][i] = 0;
        }
        for(int i = 0; i<N; i++){
            cnt[0][s[i]-'a']++;
            cnt[1][t[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(cnt[0][i] != cnt[1][i]){
                mx = N+1;
            }
        }
        for(int i = 0; i<N; i++){
            int idx = i;
            for(int j = 0; j<N; j++){
                if(idx < N && t[idx] == s[j]){
                    idx++;
                }
            }
            mx = max(mx, idx-i);
        }
        cout << N-mx << "\n";
    }
}