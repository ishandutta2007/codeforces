#include <bits/stdc++.h>

using namespace std;

string s, t;
int pre[1000005];

int main(){
    cin >> s >> t;
    int N = s.size();
    for(int i = 1; i<=s.size(); i++){
        pre[i] += s[i-1] - '0';
        pre[i] += pre[i-1];
    }
    int K = t.size();
    int cnt  = 0;
    for(int i = 1; i<=K; i++){
        cnt += t[i-1] -'0';
    }
    cnt &= 1;
    int ans = 0;
    for(int i = K; i<=N; i++){
        if((pre[i]-pre[i-K])%2 == cnt){
            ans++;
        }
    }
    cout << ans << endl;
}