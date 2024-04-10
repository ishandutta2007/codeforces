#include <bits/stdc++.h>

using namespace std;

char mp[105][105];
string s;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> s;
        for(int j = 1; j<=N; j++){
            mp[i][j] = s[j-1];
        }
    }
    int ans = 0;
    for(int i =1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(mp[i][j] == 'C'){
                cnt++;
            }
        }
                    ans += cnt*(cnt-1)/2;

    }
    for(int i =1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(mp[j][i] == 'C'){
                cnt++;
            }
        }
                    ans += cnt*(cnt-1)/2;

    }
    cout << ans << endl;
}