#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    for (int y = 2; y < x; y++)
        if (x % y == 0)
            return false;
        
    return true;
}

int main()
{
    int n;
    cin >> n;
    
    for (int m = 1; m <= 1000; m++)
        if (!isPrime(n * m + 1))
        {
            cout << m << endl;
            break;
        }
    
    
    return 0;
}