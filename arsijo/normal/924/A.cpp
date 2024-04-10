#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e2 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e9 * 1ll * 1e9;

char a[MaxN][MaxN];
char b[MaxN][MaxN];
int used1[MaxN];
int used2[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(b[i][j] == '#')
            {
                vector <int> v1, v2;

                int k = 1;
                used1[i] = 1;

                while(true)
                {
                    if(k & 1)
                    {
                        ++k;
                        bool OK = true;
                        for(int i = 1; i <= n; ++i)
                            if(used1[i] == 1)
                            {
                                OK = false;
                                used1[i] = 2;
                                for(int j = 1; j <= m; ++j)
                                    if(b[i][j] == '#' && used2[j] != 2)
                                        used2[j] = 1;

                            }
                        if(OK)
                            break;
                    }else
                    {
                        ++k;
                        bool OK = true;
                        for(int j = 1; j <= m; ++j)
                            if(used2[j] == 1)
                            {
                                OK = false;
                                used2[j] = 2;
                                for(int i = 1; i <= n; ++i)
                                    if(b[i][j] == '#' && used1[i] != 2)
                                        used1[i] = 1;

                            }
                        if(OK)
                            break;
                    }
                }

                for(int i = 1; i <= n; ++i)
                    for(int j = 1; j <= m; ++j)
                    {
                        if(b[i][j] =='.')
                        {
                            if(used1[i] && used2[j])
                                return cout << "No\n", 0;
                        }else
                        if(used1[i] && used2[j])
                            b[i][j] = '.';
                    }

                for(int i = 1; i <= n; ++i)
                    used1[i] = 0;
                for(int j = 1; j <= m; ++j)
                    used2[j] = 0;

            }

    cout << "Yes\n";

    return 0;
}