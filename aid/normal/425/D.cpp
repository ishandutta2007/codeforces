#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int MAXN = 200 * 1000 + 5, K = 500;
char c[MAXN];
vector<int> p[MAXN], small, big;
unordered_set<long long> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        st.insert((long long)x * MAXN + y);
    }
    for(int i = 0; i < MAXN; i++) {
        sort(p[i].begin(), p[i].end());
        if((int)p[i].size() <= K) {
            c[i] = true;
            small.push_back(i);
        }
        else
            big.push_back(i);
    }
    int ans = 0;
    for(size_t i = 0; i < small.size(); i++) {
        int x = small[i];
        for(size_t j = 0; j < p[x].size(); j++)
            for(size_t k = j + 1; k < p[x].size(); k++) {
                int len = p[x][k] - p[x][j];
                if(st.find((long long)(x + len) * MAXN + p[x][j]) != st.end() &&
                   st.find((long long)(x + len) * MAXN + p[x][k]) != st.end())
                    ans++;
                if(x >= len && !c[x - len] &&
                   st.find((long long)(x - len) * MAXN + p[x][j]) != st.end() &&
                   st.find((long long)(x - len) * MAXN + p[x][k]) != st.end())
                    ans++;
            }
    }
    for(size_t i = 0; i < big.size(); i++) {
        int x = big[i];
        for(size_t j = 0; j < p[x].size(); j++)
            for(size_t k = i + 1; k < big.size(); k++) {
                int len = big[k] - x;
                if(st.find((long long)(x + len) * MAXN + p[x][j]) != st.end() &&
                   st.find((long long)x * MAXN + p[x][j] + len) != st.end() &&
                   st.find((long long)(x + len) * MAXN + p[x][j] + len) !=
                   st.end())
                    ans++;
            }
    }
    cout << ans << '\n';
    return 0;
}