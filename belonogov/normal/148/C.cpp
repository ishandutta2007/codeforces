#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
     int n, a, b, i, k;
    cin >> n >> b >> a;
    if (n == 1){
        cout << 1;
        return 0;
    }
    n--;
    if (n == b){
        cout << -1;
        return 0;
    }
    cout << 1 << " ";
    k = 1;
    if (a == 0){
        n--;
        cout << 1 << " ";
    }
    for (i = 0; i < n; i++){
        if (a > 0){
            cout << k * 2 << " ";
            k *= 2;
            a--;
            continue;
        }
        if (b > 0){
            cout << ++k << " ";
            b--;
            continue;
        }
        cout << 1 << " ";
    }


    return 0;
}