#include <bits/stdc++.h>

using namespace std;

int N, M;
long long a[100005], b[100005];
long long pa[100005], pb[100005];

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=M; i++){
        cin >> b[i];
    }
    sort(a+1, a+1+N);
    sort(b+1, b+1+M);
    for(int i =1; i<=N; i++){
        pa[i] = a[i] + pa[i-1];
    }
    for(int i = 1; i<=M; i++){
        pb[i] = b[i] + pb[i-1];
    }
    long long ans = LLONG_MAX;
    for(int i = 1, j = 1; i<=N || j<=M;){
        if((j == M+1 || a[i] <= b[j]) && i != N+1){
            ans = min(ans, a[i]*i - pa[i] + pb[M] - pb[j-1] - a[i]*(M-j+1));
            i++;
        }
        else{
            ans = min(ans, b[j]*(i-1) - pa[i-1] + pb[M]-pb[j] - b[j]*(M-j));
            j++;
        }
    }
    cout << ans << endl;
}