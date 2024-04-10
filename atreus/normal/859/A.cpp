#include <bits/stdc++.h>

using namespace std;

int a[30];

int main (){
    ios_base::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    sort(a, a + k);
    if (a[k - 1] > 25)
        cout << a[k - 1] - 25;
    else
        cout << 0 << endl;
}