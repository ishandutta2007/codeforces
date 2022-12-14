#include <bits/stdc++.h>

using namespace std;

int l[120], r[120], a[120];

int main(){
    int n, p = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i <= n; i++){
        if (l[i] == 0){
            int k = i;
            while(r[k] != 0){
                a[p] = k;
                p ++;
                k = r[k];
            }
            a[p] = k;
            p ++;
        }
    }
    for (int i = 1; i <= n; i++){
        int x = a[i];
        l[x] = a[i - 1];
        r[x] = a[i + 1];
    }
    for (int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << endl;
    }
}