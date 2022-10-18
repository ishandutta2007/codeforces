#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define cb(x) ((x) * (x) * (x))
signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cubes{1};
    int cur = 1;
    while(true)
    {
        // 3 * t * t + 3 * t + 1 > cur
        double D = 3 * 3 - 4 * 3 * (1 - cur);
        double X = (-3 + sqrt(D)) / 2.;
        int x = ceil((-3 + sqrt(D)) / 2. / 3.);
        while((x + 1) * (x + 1) * (x + 1) <= x * x * x + cur)
            x++;
        if(x * x * x + cur <= n)
        {
            cubes.push_back(x);
            cur = x * x * x + cur;
        }
        else
            break;
    }
    int wo = cur;
    for(int i = cubes.size() - 1; i >= 0; i--)
    {
        while((cur - cb(cubes[i]) + cb(cubes[i] + 1)) <= n)
        {
            int two = wo + cb(cubes[i] + 1) - cb(cubes[i]);
            for(int j = i + 1; j < cubes.size(); j++)
            {
                if(two >= cb(cubes[j] + 1) - cb(cubes[j]))
                    goto fuck;
                two += cb(cubes[j]);
            }
            wo += cb(cubes[i] + 1) - cb(cubes[i]);
            cur += cb(cubes[i] + 1) - cb(cubes[i]);
            cubes[i]++;
        }
        fuck:;
        wo -= cb(cubes[i]);
    }
    cout << cubes.size() << ' ' << cur << "\n";
	return 0;
}