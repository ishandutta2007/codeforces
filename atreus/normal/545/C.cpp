#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn], hgh[maxn], rght[maxn], lft[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> hgh[i];
    lft[0] = 1;
    if (a[0] + hgh[0] < a[1])
        rght[0] = 1;
    for (int i = 1; i < n; i++){
        if (a[i] - hgh[i] > a[i - 1])
            lft[i] = lft[i - 1] + 1;
        if (hgh[i] + hgh[i - 1] < a[i] - a[i - 1])
            lft[i] = max(lft[i], rght[i - 1] + 1);
        if (a[i] + hgh[i] < a[i + 1])
            rght[i] = max(lft[i - 1], rght[i - 1]) + 1;
        if (rght[i] == 0)
            rght[i] = lft[i - 1];
        if (lft[i] == 0)
            lft[i] = max(rght[i - 1], lft[i - 1]);
    }
    int k = 0;
    rght[n - 1] = max(rght[n - 2], lft[n - 2]) + 1;
    for (int i = 0; i < n; i++){
        k = max(lft[i], k);
        k = max(rght[i], k);
    }
    cout << k << endl;
}