#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 0, v; i < n; i++) {
        cin >> v;
        s += v - 1;
        if(s % 2)
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}