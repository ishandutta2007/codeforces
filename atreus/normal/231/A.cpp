#include <iostream>

using namespace std;

int main (){
    int n, cnt = 0;
    cin >> n;
    int va[n], pe[n], to[n];
    for (int i = 0; i < n; i++){
        cin >> va[i] >> pe[i] >> to[i];
        if (va[i] + pe[i] + to[i] >= 2)
            cnt++;
    }
    cout << cnt << endl;
}