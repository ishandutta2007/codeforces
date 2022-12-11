#include <bits/stdc++.h>

using namespace std;

long long N, K;
map<long long, vector<long long>> mp;
int cnt;

void solve(long long n, long long k){
    if(n == 1 || !k){
        cout << n << " ";
        cnt++;
        if(cnt == 100000){
            exit(0);
        }
        return;
    }
    vector<long long> f;
    if(!mp.count(n)){
        for(long long i = 1; i<=sqrt(n); i++){
            if(n%i == 0){
                f.push_back(i);
                if(n/i != i){
                    f.push_back(n/i);
                }
            }
        }
        sort(f.begin(), f.end());
        mp[n] = f;
    }
    else{
        f = mp[n];
    }
    for(long long t : f){
        solve(t, k-1);
    }
}

int main(){
    cout.tie(0);
    cin >> N >> K;
    solve(N, K);
}