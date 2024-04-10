#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    bool a[500][500];
    int cnt[500];

    for(int i = 0; i < n; ++i)
    {
        cnt[i] = 0;
        int lp = -1;

        for(int j = 0; j < m; ++j)
        {
            cin >> a[i][j];

            if(a[i][j])
			{
				cnt[i] = max(cnt[i], j - lp);
			}
			else
			{
				lp = j;
			}
        }
    }

    for(int i = 0; i < q; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        a[x][y] ^= 1;

        cnt[x] = 0;
        int lp = -1;

        for(int j = 0; j < m; ++j)
		{
			if(a[x][j])
			{
				cnt[x] = max(cnt[x], j - lp);
			}
			else
			{
				lp = j;
			}
		}

        cout << *max_element(cnt, cnt + n) << endl;
    }

    return 0;
}