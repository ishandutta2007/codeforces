#include <bits/stdc++.h>

using namespace std;

int a[500005];
unordered_map < int, int > cnt;
int CNT[500005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, k, n, s, x;
    cin >> m >> k >> n >> s;
    int T = m - n * k;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= s; ++i){
        cin >> x;
        cnt[x]++;
    }
    int pred_righ = -1;
    for (int lef = 1; lef <= m; ++lef){
        int delta;
        if (lef % k == 0){
            delta = k - 1;
        }
        else{
            delta = lef % k - 1;
        }
        if (lef + k - 1 > m) break;
        int want = T - delta;
        if (want < 0){
            CNT[a[lef - 1]]--;
            continue;
        }
        want = min(want, m - (lef + k - 1));
        int len = k + want;
        if (lef == 1){
            for (int i = lef; i <= lef + len - 1; ++i){
                CNT[a[i]]++;
            }
        }
        else{
            CNT[a[lef - 1]]--;
            int righ = lef + len - 1;
            if (righ < pred_righ) for (int i = pred_righ; i > righ; --i) CNT[a[i]]--;
            else if (righ > pred_righ) for (int i = pred_righ + 1; i <= righ; ++i) CNT[a[i]]++;
        }
        pred_righ = len + lef - 1;
        bool f = true;
        for (auto key : cnt){
            if (CNT[key.first] < key.second){
                f = false;
                break;
            }
        }
        if (f){
            //cout << want << " " << lef << " " << lef + len - 1 << endl;
            vector < int > delete1;
            for (int i = lef - 1; i >= lef - delta; --i) delete1.push_back(i);
            for (int i = lef; i <= lef + len - 1; ++i){
                if (cnt[a[i]] <= 0 && want > 0){
                    delete1.push_back(i);
                    want--;
                }
                cnt[a[i]]--;
            }
            cout << delete1.size() << '\n';
            for (auto key : delete1) cout << key << " ";
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}