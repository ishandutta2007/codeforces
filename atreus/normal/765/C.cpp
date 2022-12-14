#include <bits/stdc++.h>

using namespace std;

map <int, int> mp;
int a[200];

int main(){
    ios_base::sync_with_stdio(false);
    int k, a, b;
    cin >> k >> a >> b;
    int x = a / k;
    if (x == 0){
        if (b % k == 0 && b / k != 0){
            cout << b / k << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    int y = b / k;
    if (y == 0){
        if (a % k == 0 && a / k != 0){
            cout << a / k << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << x + y << endl;
}