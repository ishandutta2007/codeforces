#include <bits/stdc++.h>

using namespace std;

bool litz[2100], litx[2100];

int main(){
    ios_base::sync_with_stdio(false);
    int p, q, l, r, a, b;
    cin >> p >> q >> l >> r;
    for (int i = 0; i < p; i++){
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            litz[j] = true;
    }
    for (int i = 0; i < q; i++){
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            litx[j] = true;
    }
    int cnt = 0;
    for (int i = l; i <= r; i++){
        for (int j = 0; j <= 1000; j++){
            if (litx[j] == true && litz[j + i] == true){
                cnt ++;
                break;
            }
        }
    }
    cout << cnt << endl;
}