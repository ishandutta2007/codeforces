#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main(){
    cin >> N;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i<N-10; i++){
        if(s[i] == '8'){
            cnt++;
        }
    }
    N-=10;
    if(cnt > N/2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}