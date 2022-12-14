#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int a[maxn + 100], b[maxn + 100], c[maxn + 100];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    for (int i = 0; i < n - 2; i++)
        cin >> c[i];
    sort (a, a + n);
    sort (b, b + n - 1);
    sort (c, c + n - 2);
    bool ok = false;
    for (int i = 0; ok == false && i < n - 1; i++)
        if (a[i] != b[i]){
            ok = true;
            cout << a[i] << endl;
        }
    if (ok == false)
        cout << a[n - 1] << endl;
    ok = false;
    for (int i = 0; ok == false && i < n - 2; i++){
        if (b[i] != c[i]){
            ok = true;
            cout << b[i] << endl;
        }
    }
    if (ok == false)
        cout << b[n - 2] << endl;
    return 0;
}