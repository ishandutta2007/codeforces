#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, f, k, rfl = 0;
    cin >> a >> b >> f >> k;
    int j = b;
    j -= f;
    if (j < 0)
        return cout << -1, 0;
    for (int i = 1; i < k; i++){
        if (i % 2 == 1){
            if (j < 0)
                return cout << -1, 0;
            if (j >= 2 * (a - f)){
                j -= 2 * (a - f);
                continue;
            }
            else {
                rfl ++;
                j = b;
                j -= (2 * (a - f));
            }
        }
        if (i % 2 == 0){
            if (j < 0)
                return cout << -1, 0;
            if (j >= (2 * f)){
                j -= 2 * f;
                continue;
            }
            else {
                rfl ++;
                j = b;
                j -= 2 * f;
            }
        }
    }
    if (j < 0)
        return cout << -1, 0;
    if (k % 2 == 0 && j < f){
        rfl ++;
        j = b;
        j -= f;
    }
    if (k % 2 == 1 && j < a - f){
        rfl ++;
        j = b;
        j -= a - f;
    }
    if (j < 0)
        return cout << -1, 0;
    cout << rfl << endl;
}