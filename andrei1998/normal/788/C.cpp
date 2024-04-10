#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool freq[1005];

int least[2005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= K; ++ i) {
        int val;
        cin >> val;
        freq[val] = true;
    }

    queue <int> q;

    vector <int> vals;
    for (int i = 0; i <= 1000; ++ i)
        if (freq[i]) {
            vals.push_back(i - N);
            least[i - N + 1000] = 1;
            q.push(i - N + 1000);
        }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it: vals)
            if (node + it >= 0 && node + it <= 2000 && !least[node + it]) {
                least[node + it] = 1 + least[node];
                q.push(node + it);
            }
    }

    if (least[1000])
        cout << least[1000] << '\n';
    else
        cout << "-1\n";
    return 0;
}