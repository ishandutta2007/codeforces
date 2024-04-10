#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[200005];
int brr[200005];
int BIT[500005];

void upd(int n){
    n += N+1;
    for(int i = n; i<=2*N+1; i+=i&-i){
        BIT[i]++;
    }
}

long long query(int n){
    long long ret = 0;
    n += N+1;
    for(int i = n; i; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

long long solve(int m){
    long long ret = 0;
    upd(0);
    for(int i = 1; i<=N; i++){
        brr[i] = brr[i-1];
        if(arr[i] >= m){
            brr[i]++;
        }
        else{
            brr[i]--;
        }
        ret += query(brr[i]-1);
        upd(brr[i]);
    }
    fill(BIT+1, BIT+2+2*N, 0);
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    cout << solve(M)-solve(M+1) << endl;
}