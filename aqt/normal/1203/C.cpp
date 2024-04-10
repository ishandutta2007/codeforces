#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[400005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long gcd = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        gcd = __gcd(gcd, arr[i]);
    }
    int cnt = 0;
    for(long long  i = 1; i<=sqrt(gcd); i++){
        if(gcd%i == 0){
            cnt++;
            if(gcd/i != i){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}