#include <bits/stdc++.h>

using namespace std;

typedef long long li;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n <= 2)
    {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
        cout << '\n';
        return 0;
    }
    
    vector<char> isNotPrime(n + 2, false);
    
    cout << "2\n";
    for (int i = 2; i <= n + 1; i++)
    {
        if (isNotPrime[i])
        {
            cout << "1 ";
            continue;
        }
        
        cout << "2 ";
        
        for (li j = i * (li)i; j <= n + 1; j += i)
            isNotPrime[j] = true;
    }
    cout << endl;
    
    return 0;
}