#include <bits/stdc++.h>

using namespace std;

int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cout << char('a' + i%k);
}