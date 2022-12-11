#include <bits/stdc++.h>

using namespace std;

string s, t;
int pre[200005], suf[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    int N = s.size(), M = t.size();
    for(int l = 1, r = 1; r<=N; r++){
        if(l <= M && t[l-1] == s[r-1]){
            pre[r] = l++;
        }
        else{
            pre[r] = l-1;
        }
    }
    for(int l = M, r = N; r>0; r--){
        if(l && t[l-1] == s[r-1]){
            suf[r] = l--;
        }
        else{
            suf[r] = l+1;
        }
    }
    suf[N+1] = M+1;
    for(int i = 1; i<=N; i++){
        //cout << " " << pre[i] << " " << suf[i] << endl;
    }
    int ans = 0;
    for(int l = 0, r = 1; r <= N+1; r++){
        while(pre[l] < suf[r]-1 && l <= r){
            l++;
        }
        //cout << l << " " << r << endl;
        ans = max(ans, r-l-1);
    }
    cout << ans << endl;
}