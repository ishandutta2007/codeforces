#include <bits/stdc++.h>

using namespace std;

int even[2000000], odd[2000000];
int N, tot = 0;

int main(){
    cin >> N;
    long long ans = 0;
    even[0]++;
    for(int i= 1; i<=N; i++){
        int n;
        cin >> n;
        tot ^= n;
        if(i%2){
            ans += odd[tot];
            odd[tot]++;
        }
        else{
            ans += even[tot];
            even[tot]++;
        }
    }
    cout << ans << endl;
}