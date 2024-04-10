#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(0));
    long long n;
    int k;
    string ans;
    cin >> n >> k;
    long long left = 1;
    long long right = n;
    while (true)
    {
        if (right - left > 50)
        {
            long long m = (left + right) / 2;
            cout << left << " " << m << endl;
            cin >> ans;
            if (ans[0] == 'Y')
            {
                left = max(1ll, left - k);
                right = min(n, m + k);
            }
            else if (ans[0] == 'N')
            {
                left = max(1ll, m + 1 - k);
                right = min(n, right + k);
            }
            else
                return 0;
        }
        else
        {
            int m = rand() % (right - left + 1);
            cout << left + m << " " << left + m << endl;
            cin >> ans;
            if (ans[0] == 'N')
            {
                left = max(1ll, left - k);
                right = min(n, right + k);
            }
            else
                return 0;
        }
    }
}