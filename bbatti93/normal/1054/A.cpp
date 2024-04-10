#include <bits/stdc++.h>

using namespace std;

long long n, ki, x, y, z, t1, t2, t3, el, st;

int main()
{
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    st=abs(x-y)*t1;
    el=(abs(x-z)+abs(x-y))*t2+3*t3;
    if(el<=st) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}