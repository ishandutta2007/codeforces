#include <bits/stdc++.h>

using namespace std;

int n, a[100];
set<int> prime;
vector<pair<int, int>> del[100];
unordered_map<int, int> dp;

void go(int foo) {
    if(dp.count(foo)) return;
    vector<int> to;
    for(int i = 1; i <= 29; i++) {
        int bar = foo;
        for(int j = i; j <= 29; j++)
            if(bar & (1 << j)) {
                bar -= (1 << j);
                if(j != i)
                    bar |= (1 << (j - i));
            }
        if(bar == foo)
            break;
        go(bar);
        to.push_back(dp[bar]);
    }
    sort(to.begin(), to.end());
    to.erase(unique(to.begin(), to.end()), to.end());
    for(int i = 0; ; i++)
        if(i == to.size() || i != to[i]) {
            dp[foo] = i;
            break;
        }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        for(int j = 2; j * j <= x; j++)
            if(x % j == 0) {
                if(del[i].empty() || del[i].back().first != j)
                    del[i].push_back({j, 1});
                else
                    del[i].back().second++;
                x /= j;
                j--;
            }
        if(x != 1)
            if(del[i].empty() || del[i].back().first != x)
                del[i].push_back({x, 1});
            else
                del[i].back().second++;
        for(int j = 0; j < del[i].size(); j++)
            prime.insert(del[i][j].first);
    }
    int ret = 0;
    for(int x : prime) {
        int foo = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < del[i].size(); j++)
                if(del[i][j].first == x)
                    foo |= (1 << del[i][j].second);
        dp.clear();
        dp[0] = 0;
        go(foo);
        ret ^= dp[foo];
    }
    cout << (ret ? "Mojtaba" : "Arpa");
}