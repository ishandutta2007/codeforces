#include <bits/stdc++.h>

using namespace std;

int N;
int lst[1000005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long tot = 0, cnt = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        if(lst[n]){
            cnt -= lst[n];
        }
        cnt += i;
        lst[n] = i;
        tot += 2*cnt-1;
    }
    cout << tot/(1.0*N*N) << endl;
}