#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n == 1 || n == 2)
        cout << 1 << endl << 1;
    if (n == 3)
        cout << 2 << endl << 1 << " " << 3 << endl;
    if (n == 4)
        cout << 4 << endl << 3 << " " << 1 << " " << 4 << " " << 2 << endl;
    if (n >= 5){
        cout << n << endl;
        for (int i = 1; i <= n; i += 2)
            cout << i << " ";
        for (int i = 2; i <= n; i += 2)
            cout << i << " ";
    }
    return 0;
}