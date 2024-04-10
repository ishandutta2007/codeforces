#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int cnt = 0;
    vector<int> mn, mx;
    for(int i = 1; i<=N; i++){
        int k;
        cin >> k;
        int lst;
        cin >> lst;
        k--;
        int mnn = lst, mxx = lst;
        bool des = 1;
        for(int j = 1; j<=k; j++){
            int n;
            cin >> n;
            if(n > lst){
                des = 0;
            }
            lst = n;
            mnn = min(mnn, lst);
            mxx = max(mxx, lst);
        }
        if(!des){
            cnt++;
        }
        else{
            mn.push_back(mnn);
            mx.push_back(mxx);
        }
    }
    sort(mn.begin(), mn.end());
    long long ans = 1LL*cnt*cnt + 2LL*cnt*mn.size();
    for(int n : mx){
        ans += lower_bound(mn.begin(), mn.end(), n) - mn.begin();
    }
    cout << ans << "\n";
}