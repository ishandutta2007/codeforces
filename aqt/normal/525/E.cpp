#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> mp[26];
int N, K;
long long S;
vector<long long> lft, rht;
long long pow3[26], fact[26];

int main(){
    cin >> N >> K >> S;
    fact[0] = 1;
    for(int i = 0; i<=25; i++){
        pow3[i] = pow(3, i);
    }
    for(long long i = 1; i<=19; i++){
        fact[i] = fact[i-1]*i;
    }
    for(int i =1; i<=N; i++){
        long long n;
        cin >> n;
        if(lft.size() == 14){
            rht.push_back(n);
        }
        else{
            lft.push_back(n);
        }
    }
    int lim = pow3[lft.size()];
    for(int i = 0; i<lim; i++){
        int tem = i, cnt = 0;
        long long tot = 0;
        for(int j = lft.size()-1; j>=0; j--){
            int dig = 0;
            while(tem >= pow3[j]){
                tem -= pow3[j];
                dig++;
            }
            if(dig == 2){
                if(lft[j] >= 19){
                    cnt = 1000;
                    break;
                }
                else{
                    tot += fact[lft[j]];
                    cnt++;
                }
            }
            else if(dig == 1){
                tot += lft[j];
            }
        }
        if(cnt > K){
            continue;
        }
        mp[cnt][tot]++;
    }
    lim = pow3[rht.size()];
    long long ans = 0;
    for(int i = 0; i<lim; i++){
        int tem = i, cnt = 0;
        long long tot = 0;
        for(int j = rht.size()-1; j>=0; j--){
            int dig = 0;
            while(tem >= pow3[j]){
                tem -= pow3[j];
                dig++;
            }
            if(dig == 2){
                if(rht[j] >= 19){
                    cnt = 1000;
                    break;
                }
                else{
                    tot += fact[rht[j]];
                    cnt++;
                }
            }
            else if(dig == 1){
                tot += rht[j];
            }
        }
        if(cnt > K){
            continue;
        }
        for(int j = 0; j<=K-cnt; j++){
            ans += mp[j][S-tot];
        }
    }
    cout << ans << endl;
}