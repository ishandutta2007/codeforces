#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int lDiv[MAXN];
vector<int> pr, needPair;
vector< pair<int, int> > ans;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        int k = 0;
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            long long p = (long long)pr[j] * i;
            if(p > n)
                break;
            lDiv[p] = pr[j];
            k++;
        }
        if(lDiv[i] == i) {
            if(!k)
                continue;
            if(k & 1) {
                ans.push_back(make_pair(i, i * pr[0]));
                for(int j = 2; j < k; j += 2)
                    ans.push_back(make_pair(i * pr[j - 1], i * pr[j]));
            }
            else {
                needPair.push_back(i * pr[0]);
                ans.push_back(make_pair(i, i * pr[1]));
                for(int j = 3; j < k; j += 2)
                    ans.push_back(make_pair(i * pr[j - 1], i * pr[j]));
            }
        }
        else {
            if(!k)
                continue;
            if(!(k & 1)) {
                for(int j = 1; j < k; j += 2)
                    ans.push_back(make_pair(i * pr[j - 1], i * pr[j]));
            }
            else {
                needPair.push_back(i * pr[0]);
                for(int j = 2; j < k; j += 2)
                    ans.push_back(make_pair(i * pr[j - 1], i * pr[j]));
            }
        }
    }
    for(int i = 1; i < (int)needPair.size(); i += 2)
        ans.push_back(make_pair(needPair[i - 1], needPair[i]));
    cout << ans.size() << '\n';
    for(size_t i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}