#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    
    cout << ((a - 1) / c + 1) * ((b - 1) / c + 1) << endl;
    
    return 0;
}