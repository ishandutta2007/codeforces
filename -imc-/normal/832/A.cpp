#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    li n, k;
    cin >> n >> k;
    li turns = n / k;
    
    if (turns % 2 == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}