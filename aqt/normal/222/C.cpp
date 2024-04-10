#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2][100005];
int pf[2][10000005];
int fact[10000005];

void upd(int n, int t){
    while(n > 1){
        pf[t][fact[n]]++;
        n /= fact[n];
    }
}

int query(int n, int t){
    int ret = n;
    while(n > 1){
        if(pf[t][fact[n]]){
            ret /= fact[n];
            pf[t][fact[n]]--;
        }
        n/=fact[n];
    }
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i = 2; i<=10000000; i++){
        if(fact[i] == 0){
            for(int j= i; j<=10000000; j+=i){
                fact[j] = i;
            }
        }
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[0][i];
        upd(arr[0][i], 0);
    }
    for(int i =1; i<=M; i++){
        cin >> arr[1][i];
        upd(arr[1][i], 1);
    }
    for(int i =1 ; i<=10000000; i++){
        int m = min(pf[0][i], pf[1][i]);
        pf[0][i] = m;
        pf[1][i] = m;
    }
    for(int i = 1; i<=N; i++){
        arr[0][i] = query(arr[0][i], 0);
    }
    for(int i = 1; i<=M; i++){
        arr[1][i] = query(arr[1][i], 1);
    }
    cout << N << " " << M << endl;
    for(int i = 1; i<=N; i++){
        cout << arr[0][i] << " ";
    }
    cout << endl;
    for(int i= 1; i<=M; i++){
        cout << arr[1][i] << " ";
    }
}