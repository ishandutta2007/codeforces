#include <bits/stdc++.h>

using namespace std;

int a[111];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    int k = 0;
    int c = 0, b = 0;
    for (int i = 0; i < n - 1; i++){
        c ++;
        if (a[i] != a[i + 1]){
            k ++;
            b = c;
            c = 0;
        }
    }
    if (k > 1 || k == 0)
        cout << "NO" << endl;
    else{
        if (c + 1 == b)
            cout << "YES" << endl << a[0] << " " << a[n - 1];
        else
            cout << "NO" << endl;
    }

}