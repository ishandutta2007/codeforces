#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    vector<char> ans;
    int l = 0, r = n - 1;
    while (1)
    {
        if ((r - l + 1) <= 3)
        {
            for (int i = 0; i < ans.size(); ++i)
                putchar(ans[i]);
            if (l <= r)
                putchar(a[l]);
            for (int i = ans.size() - 1; i >= 0; --i)
                putchar(ans[i]);
            return 0;
        }
        else
        {
            for (int i = l; i < l + 3; ++i)
            {
                bool z = false;
                for (int j = r; j > r - 2; --j)
                {
                    if (a[i] == a[j])
                    {
                        z = true;
                        ans.push_back(a[i]);
                        break;
                    }
                }
                if (z)
                    break;
            }
            l += 2;
            r -= 2;
        }
    }
    return 0;
}