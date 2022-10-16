#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
using namespace std;

const int INF = 1e9 + 15;
const int mod = 1000000007;

int v[] = {0, 52, 52, 52, 52, 53, 53, 52};
int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int n;
    cin >> n;
    string aux;

    cin >> aux;
    string type;
    cin >> type;

    if (type == "week") {
        cout << v[n] << endl;
    }
    else {
        int ans = 0;
        for (int i = 1; i <= 12; ++ i)
            if (n <= days[i])
                ++ ans;
        cout << ans << '\n';
    }

    return 0;
}