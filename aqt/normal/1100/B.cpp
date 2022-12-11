#include <bits/stdc++.h>

using namespace std;

int K, N;
int fre[100005];

int main(){
    cin >> K >> N;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        fre[n]++;
        if(fre[n] == 1){
            cnt++;
        }
        if(cnt == K){
            cout << 1;
            for(int i = 1; i<=K; i++){
                fre[i]--;
                if(fre[i] == 0){
                    cnt--;
                }
            }
        }
        else{
            cout << 0;
        }
    }
}