#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int N = s.size();
    if(N%2 == 0){
        cout << N/2 << endl;
        return 0;
    }
    bool zero = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i] == '1'){
            zero = 0;
        }
    }
    if(!zero){
        cout << N/2+1 << endl;
    }
    else{
        cout << N/2 << endl;
    }
}