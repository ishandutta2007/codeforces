#include <bits/stdc++.h>

using namespace std;

int main (){
    int k, l, m, n, d;
    int cnt = 0;
    cin >> k >> l >> m >> n >> d;
    for (int i = 1; i <= d; i++)
        if (i % l != 0 && i % k != 0 && i % m != 0 && i % n != 0)
            cnt++;
    cout << d - cnt << endl;
}