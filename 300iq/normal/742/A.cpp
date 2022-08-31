#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
       
int bin(int a, int n)
{
    if (n == 0)
    {  
        return 1;
    }
    else if (n % 2 == 0)
    {
        int t = bin(a, n / 2);
        return (t * t) % 10;
    }
    else
    {
        int t = bin(a, n - 1);
        return (t * a) % 10;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << bin(1378, n) << endl;
}