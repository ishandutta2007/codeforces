#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
    string a;
    cin >> a;
    for (int i = 2; i < a.size(); i++)
    {
        if ((a[i - 2] + a[i - 1] - 'A' - 'A') % 26 != a[i] - 'A')
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}