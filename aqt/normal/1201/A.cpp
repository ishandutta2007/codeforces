#include <bits/stdc++.h>

using namespace std;

int N, M;
string arr[1005];
int cnt[5];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int m = 0; m<M; m++){
        int p;
        cin >> p;
        fill(cnt, cnt+5, 0);
        int mx = 0;
        for(int j = 1; j<=N; j++){
            cnt[arr[j][m] - 'A']++;
            mx = max(mx, cnt[arr[j][m]-'A']);
        }
        ans += p*mx;
    }
    cout << ans << endl;
}