#include <bits/stdc++.h>

using namespace std;

int pre[5005], suf[5005];
string s;

int main(){
    cin >> s;
    int N = s.size();
    for(int i = 1; i<=s.size(); i++){
        if(s[i-1] == 'a'){
            pre[i]++;
        }
        pre[i] += pre[i-1];
    }
    pre[N+1] = pre[N];
    int ans = 0;
    for(int i =0; i<=N; i++){
        for(int j= i+1; j<=N+1; j++){
            ans = max(pre[i] + pre[N] - pre[j-1] + j-1-(i+1)+1 - pre[j-1] + pre[i], ans);
        }
    }
    cout << ans << endl;
}