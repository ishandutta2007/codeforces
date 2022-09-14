#include<bits/stdc++.h>

using namespace std;

bool fight(int hp2, int atk2, int def2, int hp1, int atk1, int def1)
{
    int s1, s2, t1, t2;
    s1 = max(0, atk2 - def1);
    s2 = max(0, atk1 - def2);
    if (s1 == 0)
        t1 = 1000000000;
    else
        t1 = (hp1 - 1) / s1 + 1;
    if (s2 == 0)
        t2 = 1000000000;
    else
        t2 = (hp2 - 1) / s2 + 1;
    if (t1 > t2)
        return true;
    else
        return false;
}

int main()
{
    int hp1, atk1, def1, hp2, atk2, def2, h, a, d, i, j, k, cost;
    cin >> hp1 >> atk1 >> def1;
    cin >> hp2 >> atk2 >> def2;
    cin >> h >> a >> d;
    cost = 1000000000;
    for (i = 0; i <= 1000; i++)
        for (j = 0; j <= 201; j++)
            for (k = 0; k <= 201; k++)
            if (fight(hp2, atk2, def2, i, j, k))
                if (i >= hp1 && j >= atk1 && k >=def1)
                    cost = min (cost, (i - hp1) * h + (j - atk1) * a + (k - def1) * d);

    cout << cost;
    return 0;

}