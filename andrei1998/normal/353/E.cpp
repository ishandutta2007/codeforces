#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 1000000 + 5;

int N;
string edges;

vector <int> chains;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> edges;
    N = edges.size();

    int pos;
    for (int i = 0; i < N; ++ i)
        if (edges[i] != edges[0]) {
            pos = i;
            break;
        }
    rotate(edges.begin(), edges.begin() + pos, edges.end());

    int j;
    for (int i = 0; i < N; i = j + 1) {
        j = i;
        while (j + 1 < N && edges[i] == edges[j + 1])
            ++ j;
        chains.push_back(j - i + 2);
    }

    int pos3 = -1;
    for (int i = 0; i < chains.size(); ++ i)
        if (chains[i] >= 3) {
            pos3 = i;
            break;
        }

    if (pos3 == -1) {
        //Only 2s
        cout << chains.size() / 2 << '\n';
        return 0;
    }

    int ans = 1;
    rotate(chains.begin(), chains.begin() + (pos3 + 1) % chains.size(), chains.end());

    chains.pop_back();
    chains[0] --;
    chains.back() --;

    if (chains[0] == 0) {
        cout << ans << '\n';
        return 0;
    }

    for (int i = 0; i < chains.size(); ++ i) {
        if (chains[i] > 1) {
            ++ ans;
            if (i + 1 < chains.size())
                chains[i + 1] --;
        }
        else if (chains[i] == 1 && i + 1 == chains.size())
            ++ ans;
    }

    cout << ans << '\n';
    return 0;
}