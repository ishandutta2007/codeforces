#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[200005];
int cnt[100];

int main(){
    cin >> N;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
        cnt[__builtin_ctzll(arr[i])]++;
    }
    int b = 0;
    for(int i= 0; i<100; i++){
        if(cnt[i] > cnt[b]){
            b = i;
        }
    }
    cout << N-cnt[b] << endl;
    for(int i = 1; i<=N; i++){
        if(__builtin_ctzll(arr[i]) != b){
            cout << arr[i] << " ";
        }
    }
}