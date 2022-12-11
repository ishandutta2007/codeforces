#include <bits/stdc++.h>

using namespace std;

int N, K;
long long T = 1100000000;
vector<int> cmp;
int lst[30000005];
long long ans[100005];
int cnt[30000005];
vector<pair<pair<int, int>, int>> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        cmp.push_back(y);
        v.push_back({{x, y}, 1});
        v.push_back({{x+K, y}, -1});
    }
    sort(cmp.begin(), cmp.end());
    int idx = 0;
    lst[0] = INT_MIN;
    for(int n : cmp){
        for(int j = 0; j<K; j++){
            if(lst[idx] < n + j){
                lst[++idx] = n + j;
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto q : v){
        int x = q.first.first, y = q.first.second, v = q.second;
        y = lower_bound(lst+1, lst+idx+1, y)-lst;
        for(int i = y; i<y+K; i++){
            ans[cnt[i]] -= (T - x);
            cnt[i] += v;
            ans[cnt[i]] += (T - x);
        }
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}