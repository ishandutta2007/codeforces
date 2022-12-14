#include <bits/stdc++.h>

using namespace std;

int a[10000];

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int p = 0;
    for (int i = 1; i <= sqrt(n) + 1; i++){
        for (int j = 1; j <= sqrt(n) + 1; j++){
            if (i * j >= n){
                a[p] = 2 * i + 2 * j;
                p ++;
            }
        }
    }
    int b = 10000000;
    for (int i = 0; i < p; i++){
        b = min(b, a[i]);
    }
    cout << b << endl;
}