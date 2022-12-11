#include <bits/stdc++.h>

using namespace std;

string s, t;
long long hsh[1000005];
long long powsd[1000005];
long long seed = 31;
long long MOD = 1e9+7;

long long gethash(int l, int r){
    assert(r <= 1000000);
    return (hsh[r] - (hsh[l]*powsd[r-l])%MOD + MOD)%MOD;
}

int main(){
    cin >> s >> t;
    int N = (int) (s.size()), M = (int) (t.size());
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i<N; i++){
        if(s[i] == '0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
    }
    powsd[0] = 1;
    for(int i =1 ; i<=max(N, M); i++){
        powsd[i] = powsd[i-1]*seed%MOD;
        hsh[i] = (hsh[i-1]*seed + t[i-1] - 'a' + 1)%MOD;
    }
    int ans = 0;
    for(int i = 1; i<M/cnt0; i++){
        if((1LL*M-1LL*cnt0*i)%cnt1 != 0){
            continue;
        }
        int l0 = i, l1 = (int) ((1LL*M-1LL*cnt0*i)/cnt1);
        if(l1 <= 0){
            continue;
        }
        long long sd0 = -1, sd1 = -1;
        int idx = 0;
        bool p = 1;
        for(int j = 0; j<N; j++){
            if(s[j] == '0'){
                long long t = gethash(idx, idx+l0);
                if(sd0 == -1){
                    sd0 = t;
                }
                else if(sd0 != gethash(idx, idx+l0)){
                    p = 0;
                }
                idx += l0;
            }
            else{
                long long t = gethash(idx, idx+l1);
                if(sd1 == -1){
                    sd1 = t;
                }
                else if(sd1 != gethash(idx, idx+l1)){
                    p = 0;
                }
                idx += l1;
            }
        }
        if(p && sd0 != sd1){
            ans++;
        }
    }
    cout << ans << endl;
}