#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

string s;
set <string> S;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    while (cin >> s)
    {
        sort(s.begin(), s.end());
        S.clear();
        do
        {
            string c = s;
            string res = c;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        res = min(res, c);
                        swap(c[1], c[4]);
                        swap(c[4], c[3]);
                        swap(c[3], c[5]);
                    }
                    swap(c[0], c[1]);
                    swap(c[1], c[2]);
                    swap(c[2], c[3]);
                }
                swap(c[0], c[4]);
                swap(c[4], c[2]);
                swap(c[2], c[5]);
            }
            S.insert(res);
        } while (next_permutation(s.begin(), s.end()));
        printf("%d\n", S.size());
    }
    return 0;
}