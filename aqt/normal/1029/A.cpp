#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    string s;
    cin >> N >> K;
    cin >> s;
    int bor = 0;
    for(int i = 0; i<N; i++){
        if(s.substr(0, i) == s.substr(N-i, i)){
            bor = i;
        }
    }
    cout << s;
    K--;
    while(K--){
        cout << s.substr(bor);
    }
}