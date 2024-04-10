#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    cout << s[(n-1)/2];
    if (n%2==1){
        for (int i=1; i<=(n-1)/2; i++){
            cout << s[(n-1)/2+i] << s[(n-1)/2-i];
        }
    } else {
        for (int i=1; i<=(n-1)/2; i++){
            cout << s[(n-1)/2+i] << s[(n-1)/2-i];
        }
        cout << s[n-1];
    }
}