#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long temp;
    long long ans = 0;
    long long cur = 1;
    for(long long i = 0; i < m; i++)
    {
        cin >> temp;
        ans += (3 * n - cur + temp) % n;
        cur = temp;
    }
    cout << ans;
    return 0;
}