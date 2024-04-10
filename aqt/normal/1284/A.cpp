#include <bits/stdc++.h>

using namespace std;

int Q, N, M;
string s[25], t[25];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> s[i];
    }
    for(int j = 0; j<M; j++){
        cin >> t[j];
    }
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        n--;
        cout << s[n%N] << t[n%M] << "\n";
    }
}