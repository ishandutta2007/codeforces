#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

char str[100005];
int s_part[100005];

int main()
{
    cin.get(str + 1, 100005);
    int n = strlen(str + 1);

    for (int i = 1; i < n; i++)
        s_part[i] = s_part[i - 1] + (str[i] == str[i + 1]);

    int m = 0;
    cin >> m;

    int l, r;
    while (m--) {
        cin >> l >> r;
        r--;

        cout << s_part[r] - s_part[l - 1] << endl;
    }

    return 0;
}