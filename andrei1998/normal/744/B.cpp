#include <iostream>
#include <vector>

using namespace std;

int ans[1005];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++ i)
        ans[i] = 1e9 + 15;

    for (int bit = 0; bit < 10; ++ bit)
        for (int val = 0; val < 2; ++ val) {
            vector <int> toAsk;
            for (int i = 0; i < n; ++ i)
                if ((i & (1 << bit)) == val * (1 << bit))
                    toAsk.push_back(i + 1);

            if (toAsk.size() > 0) {
                cout << toAsk.size() << endl;
                for (int i = 0; i < toAsk.size(); ++ i)
                    cout << toAsk[i] << " \n"[i + 1== toAsk.size()];
                cout.flush();

                for (int i = 0; i < n; ++ i) {
                    int anss;
                    cin >> anss;
                    if ((i & (1 << bit)) != val * (1 << bit))
                        ans[i] = min(ans[i], anss);
                }
            }
        }

    cout << "-1" << endl;
    for (int i = 1; i <= n; ++ i)
        cout << ans[i - 1] << " \n"[i == n];
    return 0;
}