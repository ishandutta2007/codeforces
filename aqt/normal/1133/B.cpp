#include <bits/stdc++.h>

using namespace std;

int N, K;
int fre[105];

int main(){
    cin >> N >> K;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        n%=K;
        if(fre[(K-n)%K]){
            cnt++;
            fre[(K-n)%K]--;
        }
        else{
            fre[n]++;
        }
    }
    cout << cnt*2 << endl;
}