#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, int> M;

    int ans = 1;
    int modulo = 1000000007;

    for (int i = 0; i < n; ++i)
    {
        string s;
        int p;

        cin >> s >> p;
        if (s == "ADD")
        {
            M[p] = 0;
            auto it = M.lower_bound(p);
            auto jt = it;
            ++jt;
            if (jt != M.end() && jt->second == 1)
            {
                it->second = 1;
            }

            if (it != M.begin())
            {
                jt = it;
                --jt;
                if (jt->second == 2)
                {
                    it->second = 2;
                }
            }
        }
        else
        {
            auto it = M.lower_bound(p);
            auto jt = it;
            ++jt;
            while (jt != M.end())
            {
                if (jt->second == 1)
                {
                    cout << 0 << endl;
                    return 0;
                }
                if (jt->second == 2)
                {
                    break;
                }
                jt->second = 2;
                ++jt;
            }

            if (it != M.begin())
            {
                jt = it;
                --jt;
                while (true)
                {
                    if (jt->second == 2)
                    {
                        cout << 0 << endl;
                        return 0;
                    }
                    if (jt->second == 1)
                    {
                        break;
                    }
                    jt->second = 1;
                    if (jt == M.begin())
                    {
                        break;
                    }
                    --jt;
                }
            }

            if (it->second == 0)
            {
                ans = ans * 2 % modulo;
            }
            M.erase(it);
        }
    }

    int remaining = 0;
    for (const auto& p : M)
        if (p.second == 0)
        {
            ++remaining;
        }
    ans = ans * (1ll + remaining) % modulo;

    cout << ans << endl;

    return 0;
}