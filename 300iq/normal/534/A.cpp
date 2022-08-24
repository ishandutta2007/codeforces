#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        cout << 1;
        return 0;
    }
    if(n == 2){
        cout << 1 << endl;
        cout << 1;
        return 0;
    }
    if(n == 3){
        cout << 2 << endl;
        cout << 1 << " " << 3;
        return 0;
    }
    if(n == 4){
        cout << 4 << endl;
        cout << 3 << " " << 1 << " " << 4 << " " << 2;
        return 0;
    }
    cout << n << endl;
    int a[n];
    int b[n];
    int k = n - 1;
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            b[i] = a[k];
            k--;
        }
        else{
            b[i] = a[t];
            t++;
        }
    }
    for(int i = 0; i < n; i++){
        if(i == 0)
            cout << b[n - 1];
        else
            if(i == n - 1)
                cout << b[0];
            else
                cout << b[i];
        cout << " ";
    }
}