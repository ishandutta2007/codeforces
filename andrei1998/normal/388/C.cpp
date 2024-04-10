#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum[2];
vector <int> v;

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int sz = 0;
        cin >> sz;

        if (sz & 1) {
            for (int i = 1; i <= sz; ++ i) {
                int val;
                cin >> val;

                if (i <= sz / 2)
                    sum[0] += val;
                else if (i == (sz + 1) / 2)
                    v.push_back(val);
                else
                    sum[1] += val;
            }
        }
        else {
            for (int i = 1; i <= sz; ++ i) {
                int val;
                cin >> val;
                sum[i > sz / 2] += val;
            }
        }
    }

    sort(v.begin(), v.end(), greater <int>());
    for (int i = 0; i < v.size(); ++ i)
        sum[i & 1] += v[i];

    cout << sum[0] << ' ' << sum[1] << '\n';
    return 0;
}