#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

char a[N];
int czz, czm, cmz, cmm;

int q[N];

char ans[N];

bool solv(int z, int m)
{
    int zz = czz, zm = czm, mz = cmz, mm = cmm;
    memset(q, 0, sizeof q);
    memset(ans, '\0', sizeof ans);
    int qm = 0;
    for (int i = z; i > 0; --i)
    {
        q[i] = zm / i;
        zm %= i;
        qm += q[i];
    }
    if (qm > m)
    {
        return false;
    }
    q[0] = (m - qm);
    if (zm)
    {
        return false;
    }

    int n = 0;
    for (int i = 0; i < z; ++i)
    {
        while (q[i]--)
            ans[n++] = '1';
        ans[n++] = '0';
    }
    while (q[z]--)
        ans[n++] = '1';

    int qq = 0;
    for (int i = 0; i < z + m; ++i)
    {
        if (ans[i] == '1')
            qq++;
        else
        {
            mz -= qq;
            if (mz < 0)
            {
                return false;
            }
        }
    }
    if (mz)
    {
        return false;
    }
    cout << ans << endl;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> czz >> czm >> cmz >> cmm;

    int z;
    for (z = 0; z < N; ++z)
    {
        if (1LL * z * (z - 1) / 2 == czz)
            break;
    }
    if (z == N)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    int m;
    for (m = 0; m < N; ++m)
    {
        if (1LL * m * (m - 1) / 2 == cmm)
            break;
    }
    if (m == N)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    if ((z || m) && solv(z, m))
        return 0;
    if (z == 0)
    {
        if (solv(z + 1, m))
            return 0;
    }
    if (m == 0)
    {
        if (solv(z, m + 1))
            return 0;
    }
    if (z == 0 && m == 0)
    {
        if (solv(z + 1, z + 1))
            return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}