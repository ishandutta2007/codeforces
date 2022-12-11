#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, L, R;
    cin >> N >> L >> R;
    L--, R--;
    long long mn = 0, mx = 0;
    int s = 1<<L;
    for(int i =1 ; i<=N; i++){
        mn += s;
        s = max(s/2, 1);
    }
    s = 1;
    for(int i = 1; i<=N; i++){
        mx += s;
        s = min(s*2, (1<<R));
    }
    cout << mn << " " << mx << endl;
}