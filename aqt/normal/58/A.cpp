#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, h = "hello ";
    cin >> s;
    int N = s.size();
    int crnt = 0;
    for(int i = 1; i<=N; i++){
        if(s[i-1] == h[crnt]){
            crnt++;
        }
    }
    if(crnt == 5){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}