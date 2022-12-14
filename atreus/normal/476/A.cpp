#include <bits/stdc++.h>

using namespace std;

long long tav[50];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a = n / 2;
    int b = n % 2;
    while ((a + b) % m != 0){
        a --;
        b += 2;
        if (a == -1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << a + b << endl;
}