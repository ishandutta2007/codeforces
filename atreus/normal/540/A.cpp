#include<bits/stdc++.h>

using namespace std;

int main (){
    int c, sum = 0;
    cin >> c;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < c; i++){
        int m = a[i] - '0';
        int n = b[i] - '0';
        if (m < n)
            swap(n, m);
        int x = m - n;
        int y = (10 - m) + n;
        sum += min(x, y);
    }
    cout << sum;
    return 0;
}