#include <cstdio>
#include <iostream>

using namespace std;

const int MOD = 1000003;

long long ans;
int n;

int main()
{
    cin >> n;

    ans = 1;

    while (--n > 0)
        ans = ans * 3 % MOD;

    cout << ans << endl;
    return 0;
}