#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    cin >> s;
    bool d = 0, c = 0;
    int idx = 0;
    for(int i = 0; i<N; i++){
        if(s[i] == 'T' || s[i] == 'G'){
            idx = i;
            break;
        }
    }
    idx += K;
    for(int i = idx; i<N; i+=K){
        if(s[i] == 'T' || s[i] == 'G'){
            c = 1;
            break;
        }
        if(s[i] == '#'){
            break;
        }
    }
    if(c){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}