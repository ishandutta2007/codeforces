#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int init[105], slope[105];
bool stat[105];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s;
    for(int i = 0; i<N; i++){
        cin >> slope[i] >> init[i];
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i<N; i++){
        int k = s[i]-'0';
        stat[i] = (s[i] == '1');
        ans += k;
        cnt += k;
    }
    for(int t = 1; t<30000; t++){
        for(int i = 0; i<N; i++){
            if(t >= init[i] && t%slope[i] == init[i]%slope[i]){
                stat[i] ^= 1;
                if(stat[i]){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}