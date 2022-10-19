#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = -1;

int main()
{
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    long long ans = 0;
    ans += (w1 + h1 + h1);
    ans += 2;
    ans += (w2 + h2 + h2);
    ans += 2;
    ans += (w1 - w2);
    cout << ans << endl;
    return 0;
}