#include <bits/stdc++.h>

using namespace std;

string s, str;

int main(){
    cin >> s;
    str = s;
    int N = s.size();
    int pos = N+3;
    for(int t = 1; t<N; t++){
        str = str.substr(1) + str[0];
        bool pali = 0;
        for(int j = 0; j<N; j++){
            if(str[j] != str[N-j-1]){
                pali = 1;
                break;
            }
        }
        if(str != s && !pali){
            cout << 1 << endl;
            return 0;
        }
    }
    for(int i = 1; i<=N/2; i++){
        for(int j = 0; j<i; j++){
            if(s[j] != s[i-j-1]){
                pos = i;
                break;
            }
        }
    }
    if(pos == N+3){
        cout << "Impossible" << endl;
        return 0;
    }
    if(pos == N/2 && N%2 == 0){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
}