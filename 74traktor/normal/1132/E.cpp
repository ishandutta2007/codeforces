#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[10];
int h[10];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int w, suma = 0;
    cin >> w;
    for (int i = 1; i <= 8; ++i) cin >> a[i];
    for (int i = 1; i <= 8; ++i) suma += a[i] * i;
    if (suma <= w){
        cout << suma << '\n';
        return 0;
    }
    suma = 0;
    for (int i = 8; i >= 1; --i){
        int can = (w - suma) / i;
        int used = min(can, a[i]);
        a[i] -= used;
        suma += used * i;
        h[i] = used;
    }
    int ss = suma;
    //cout << suma << endl;
    for (int i1 = -3; i1 <= 3; ++i1){
        for (int i2 = -3; i2 <= 3; ++i2){
            for (int i3 = -3; i3 <= 3; ++i3){
                for (int i4 = -3; i4 <= 3; ++i4){
                    for (int i5 = -3; i5 <= 3; ++i5){
                        for (int i6 = -3; i6 <= 3; ++i6){
                            for (int i7 = -3; i7 <= 3; ++i7){
                                for (int i8 = -3; i8 <= 3; ++i8){
                                    vector < int > Q = {i1, i2, i3, i4, i5, i6, i7, i8};
                                    int suma1 = ss;
                                    for (int pos = 0; pos < 8; ++pos){
                                        if (Q[pos] >= 0){
                                            int can = min(Q[pos], a[pos + 1]);
                                            suma1 += can * (pos + 1);
                                        }
                                        else suma1 -= min(h[pos + 1], -1 * Q[pos]) * (pos + 1);
                                    }
                                    if (suma1 <= w) suma = max(suma, suma1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << suma << endl;
    return 0;
}