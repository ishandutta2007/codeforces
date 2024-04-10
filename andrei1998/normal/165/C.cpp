#include <bits/stdc++.h>

#define mod 1000000007
#define lint long long int
#define mp make_pair
#define pb push_back
#define lsb(x) ((x) & (-(x)))
using namespace std;

string str;
int s_part[1000005];

int sum (int a, int b) {
    return s_part[b] - s_part[a - 1];
}

lint get (int n, int k) {
    lint ans = 0;
    for (int i = 1; i <= n; i++) {
        int st = i;
        int dr = n;
        int mijl;
        int rasp = st - 1;

        while (st <= dr) {
            mijl = (st + dr) / 2;

            if (sum(i, mijl) <= k) {
                rasp = mijl;
                st = mijl + 1;

//                cout << "merge " << mijl << endl;
            }
            else
                dr = mijl - 1;
        }
        //cout << "la " << i << " ans = =" << rasp << endl;

        ans += (rasp - i + 1);
    }

    return ans;
}

int main()
{
    int k = 0;

    cin >> k;
    cin >> str;
    str = '0' + str;

    int n = str.size() - 1;

    for (int i = 1; i <= n; i++)
        s_part[i] = s_part[i - 1] + str[i] - '0';

    cout << get(n, k) - get(n, k - 1) << '\n';
    return 0;
}