#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    long long n;
    cin >> n;
    
    if(n%2==0)
    {
        cout << 4 << " " << n-4;
    }
    
    else
    {
        cout << 9 << " " << n-9;
    }
}