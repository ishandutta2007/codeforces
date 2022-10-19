#include <bits/stdc++.h>
using namespace std;

int hpy, atky, defy;
int hpm, atkm, defm;
int h, a, d;

bool stg(int x)
{
    if (x == 0)
        cout << "";
    for (int aa = 0; aa < 202; ++aa)
    {
        for (int dd = 0; dd < 202; ++dd)
        {
            int xx = x;
            atky += aa;
            xx -= (aa * a);
            defy += dd;
            xx -= (dd * d);
            if (xx >= 0)
            {
                hpy += (xx / h);
                if ((atky > defm) && (atkm <= defy || (hpm / (atky - defm) + !!(hpm % (atky - defm))) < (hpy / (atkm - defy) + !!(hpy % (atkm - defy)))))
                {
                    atky -= aa;
                    defy -= dd;
                    hpy -= (xx / h);
                    return true;
                }
                hpy -= (xx / h);
            }
            atky -= aa;
            defy -= dd;
        }
    }
    return false;
}

int main()
{
    cin >> hpy >> atky >> defy;
    cin >> hpm >> atkm >> defm;
    cin >> h >> a >> d;
    int l = 0, r = (hpm + defm + defm) * a + atkm * d;
    while ((r - l) > 3)
    {
        int m = (l + r) / 2;
        if (stg(m))
            r = m;
        else
            l = m;
    }
    for (int m = l; m <= r; ++m)
    {
        if (stg(m))
        {
            cout << m << endl;
            return 0;
        }
    }
    return 0;
}