#include <bits/stdc++.h>

using namespace std;

int N, M, K = 512;
pair<int, int> bpiz[512][2];
int cnt[512], tot[512];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=N; i++){
        int n, m = 0;
        cin >> n;
        for(int j = 0; j<n; j++){
            int k;
            cin >> k;
            k--;
            m |= (1<<k);
        }
        cnt[m]++;
    }
    for(int m = 0; m<K; m++){
        for(int k = 0; k<=m; k++){
            if((k|m) == m){
                tot[m] += cnt[k];
            }
        }
    }
    for(int i = 1; i<=M; i++){
        int n, m = 0, c;
        cin >> c >> n;
        for(int j = 0; j<n; j++){
            int k;
            cin >> k;
            k--;
            m |= (1<<k);
        }
        if(bpiz[m][0].second == 0 || bpiz[m][0].first >= c){
            swap(bpiz[m][1].second, bpiz[m][0].second);
            swap(bpiz[m][1].first, bpiz[m][0].first);
            bpiz[m][0].second = i;
            bpiz[m][0].first = c;
        }
        else if(bpiz[m][1].second == 0 || bpiz[m][1].first > c){
            bpiz[m][1].second = i;
            bpiz[m][1].first = c;
        }
    }
    int ans1 = -1;
    pair<int, int> ans2 = {0, 0};
    int ans3 = 0;
    for(int m1 = 0; m1<K; m1++){
        if(bpiz[m1][1].second){
            int m = m1;
            if(tot[m] > ans1){
                ans1 = tot[m];
                ans2.first = bpiz[m][0].second, ans2.second = bpiz[m][1].second;
                ans3 = bpiz[m][0].first + bpiz[m][1].first;
            }
            else if(tot[m] == ans1 && ans3 > bpiz[m][0].first + bpiz[m][1].first){
                ans2.first = bpiz[m][0].second, ans2.second = bpiz[m][1].second;
                ans3 = bpiz[m][0].first + bpiz[m][1].first;
            }
        }
        for(int m2 = m1+1; m2<K; m2++){
            if(!bpiz[m1][0].second || !bpiz[m2][0].second){
                continue;
            }
            int m = m1|m2;
            int v = 0;
            for(int k = 0; k<K; k++){
                if((m|k) == m){
                    v += cnt[k];
                }
            }
            if(v > ans1 || (v == ans1 && ans3 > bpiz[m1][0].first + bpiz[m2][0].first)){
                ans1 = v;
                ans2.first = bpiz[m1][0].second, ans2.second = bpiz[m2][0].second;
                ans3 = bpiz[m1][0].first + bpiz[m2][0].first;
            }
        }
    }
    cout << ans2.first << " " << ans2.second << "\n";
}