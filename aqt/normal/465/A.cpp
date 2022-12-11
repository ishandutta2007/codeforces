#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    for(int i = 1; i<=N; i++){
        if(s[i-1] == '0'){
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;
}