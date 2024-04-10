#include <bits/stdc++.h>

using namespace std;

int a[120];

int main(){
    int n, k = 0, l = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a == 1)
            k ++;
        if (a == 0 && k > 0){
            k --;
            l ++;
        }
    }
    cout << n - l << endl;
}