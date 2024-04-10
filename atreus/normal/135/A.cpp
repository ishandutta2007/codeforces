#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    bool cur = false;
    if (n == 1){
        if (a[0] == 1)
            cout << 2 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    cout << 1 << " ";
    if (a[0] > 1)
        cur = true;
    for (int i = 1; i < n - 1; i++){
        cout << a[i - 1] << " ";
        if (a[i] > 1)
            cur = true;
    }
    if (n == 2){
        if (a[0] == 1 && a[1] != 1)
            cout << 1 << endl;
        else
            cout << max(a[n - 1], 2) << endl;
        return 0;
    }
    if (cur == true)
        cout << a[n - 2] << endl;
    else{
        if (a[n - 1] != 1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}