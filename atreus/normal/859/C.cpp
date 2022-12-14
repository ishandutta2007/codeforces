#include <bits/stdc++.h>

using namespace std;

int s[50];

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    int a = 0, b = 0;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] + b > a){
            b += s[i];
            swap(a, b);
        }
        else{
            b += s[i];
        }
    }
    cout << b << " " << a;
}