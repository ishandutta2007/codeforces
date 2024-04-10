#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[300005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
        mnx = min(mnx, arr[i].first);
        mxx = max(mxx, arr[i].first);
        mny = min(mny, arr[i].second);
        mxy = max(mxy, arr[i].second);
    }
    int ans = 0;
    for(int i = 1; i<=N; i++){
        ans = max(ans, 2*max(arr[i].first-mnx, mxx-arr[i].first) +
                  2*max(arr[i].second-mny, mxy-arr[i].second));
    }
    cout << ans << " ";
    for(int i = 4; i<=N; i++){
        cout << 2*(mxx-mnx+mxy-mny) << " ";
    }
}