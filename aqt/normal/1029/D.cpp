#include <bits/stdc++.h>

using namespace std;

map<int, int> mp[11];
unsigned long long arr[200005];

int main(){
    int N, K;
    cin >> N >> K;
    long long p[11];
    p[0] = 1;
    for(int i = 1; i<=10; i++){
        p[i] = p[i-1]*10;
    }
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        for(int j = 1; j<=10; j++){
            mp[j][(int) ((arr[i]*p[j])%K)]++;
        }
    }
    long long ans = 0;
    for(int i =1; i<=N; i++){
        ans += mp[(int) log10(arr[i])+1][(K-(arr[i]%K))%K];
        if((arr[i]*p[(int) log10(arr[i])+1])%K == (K-(arr[i]%K))%K){
            ans--;
        }
    }
    cout << ans << endl;
}