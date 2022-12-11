#include <bits/stdc++.h>

using namespace std;

int N, K, M;

int main(){
    cin >> N >> M >> K;
    long long maxf = 0, maxs = 0;
    for(int i = 1; i<=N; i++){
        long long n;
        cin >> n;
        if(n > maxf){
            maxs = maxf;
            maxf = n;
        }
        else if(n > maxs){
            maxs = n;
        }
    }
    cout << M/(K+1)*(maxf*K+maxs)+((M%(K+1))*maxf) << endl;
}