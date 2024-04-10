#include <iostream>
#include <vector>

using namespace std;

int vect(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    vector<pair<int, int>> v(n);
    vector<bool> used(n);
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(used[i])
            continue;
        ++ans;
        int x1 = v[i].first, y1 = v[i].second;

        for(int j = 0; j < n; ++j)
        {
            int x2 = v[j].first, y2 = v[j].second;
            if(vect(x1 - x0, y1 - y0, x2 - x0, y2 - y0) == 0)
            {
                used[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}