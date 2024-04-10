#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= a; b++)
        {
            int c = a ^ b;
            if (c <= b && c + b > a)
                ans++;
        }
    }
    cout << ans;
}