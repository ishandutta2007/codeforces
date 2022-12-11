#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> pr;
int basis[20];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 2; i<=70; i++){
        bool isp = 1;
        for(int j = 2; j<i; j++){
            if(i%j == 0){
                isp = 0;
            }
        }
        if(isp){
            pr.push_back(i);
        }
    }
    int sz = 0;
    for(int i = 0; i<N; i++){
        int n;
        cin >> n;
        int msk = 0;
        for(int b = 0; b<19; b++){
            while(n%pr[b] == 0){
                msk ^= (1<<b);
                n /= pr[b];
            }
        }
        n = msk;
        for(int b = 0; b<19; b++){
            if((n&(1<<b)) == 0){
                continue;
            }
            if(!basis[b]){
                basis[b] = n;
                sz++;
            }
            n ^= basis[b];
        }
    }
    long long ans = 1, MOD = 1e9+7;
    for(int i = 0; i<N-sz; i++){
        ans *= 2;
        ans %= (long long) (MOD);
    }
    cout << (ans-1+MOD)%MOD << endl;
}