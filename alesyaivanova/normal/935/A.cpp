#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= int(sqrt(n)); i++)
    {
        if (n % i == 0)
            ans += 2;
    }
    int j = int(sqrt(n));
    if (j * j == n)
        ans--;
    j++;
    if (j * j == n)
        ans++;
    ans--;
    cout << ans;
}