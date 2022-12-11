#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
int ans[1000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    if(K < 1LL*N*(N+1)/2){
        cout << -1 << endl;
        return 0;
    }
    long long sum = 1LL*N*(N+1)/2;
    for(int i = 1; i<=N; i++){
        ans[i] = i;
    }
    for(int l = 1, r = N; l<=r; r--, l++){
        while(r-l > K-sum){
            l++;
        }
        sum += r-l;
        swap(ans[l], ans[r]);
    }
    cout << sum << "\n";
    for(int i = 1; i<=N; i++){
        cout << i << " ";
    }
    cout << "\n";
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}