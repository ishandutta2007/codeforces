#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int main(){
    cin >> N;
    cin >> s;
    for(int i = 1; i<N; i++){
        if(s[i] < s[i-1]){
            cout << "YES" << endl;
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}