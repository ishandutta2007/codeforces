#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, s, x;
    cin >> t >> s >> x;
    if(x < t) cout << "NO";
    else if((x-t)%s == 0 || ((x-t)%s == 1 && x != t+1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}