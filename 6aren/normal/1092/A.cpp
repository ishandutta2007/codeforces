#include <bits/stdc++.h>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    while (ntest--){
        int n, k;
        cin >> n >> k;
        char a='a';
        for (int i=1; i<=k ;i++){
            for (int j=1; j<=n/k; j++){
                cout << a;
            }
            a++;
        }
        for (int i=(n/k)*k+1; i<=n; i++){
            cout << 'a';
        }
        cout << endl;
    }
}