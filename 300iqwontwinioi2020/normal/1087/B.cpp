#include <bits/stdc++.h>

using namespace std;

int n, k, x = 1e9 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i = 1; i < k; i++){
        if (n % i > 0)
            continue;
        int j = n / i;
        int y = k * j + i;
        x = min (x, y);
    }
    cout<<x<<endl;
    return 0;
}