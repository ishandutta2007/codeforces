#include <bits/stdc++.h>

using namespace std;

int N, M;
bool tkn[100005];
int suf[100005];
int arr[100005];

int main(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i = N; i>0; i--){
        suf[i] = suf[i+1];
        if(!tkn[arr[i]]){
            suf[i]++;
        }
        tkn[arr[i]] = 1;
    }
    while(M--){
        int i;
        cin >> i;
        printf("%d\n", suf[i]);
    }
}