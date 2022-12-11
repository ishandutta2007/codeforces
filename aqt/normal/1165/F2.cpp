#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> sale[200005];
int amt[200005];
int t[200005];
int b[200005];

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> amt[i];
    }
    for(int i = 1; i<=M; i++){
        cin >> sale[i].second >> sale[i].first;
    }
    int l = 1, r = 500000, ans = 1000000;
    while(l <= r){
        int mid = l+r>>1;
        fill(b, b+1+N, 0);
        for(int i = 1; i<=N; i++){
            t[i] = amt[i];
        }
        for(int i =1; i<=M; i++){
            if(sale[i].second <= mid){
                b[sale[i].first] = max(b[sale[i].first], sale[i].second);
            }
        }
        vector<pair<int, int>> v;
        for(int i = 1; i<=N; i++){
            if(b[i]){
                v.push_back({b[i], i});
            }
        }
        sort(v.begin(), v.end());
        int lst = 0, val = 0;
        for(auto p : v){
            val += p.first - lst;
            lst = p.first;
            if(val > t[p.second]){
                val -= t[p.second];
                t[p.second] = 0 ;
            }
            else{
                t[p.second] -= val;
                val = 0;
            }
        }
        int tot = 0;
        for(int i = 1; i<=N; i++){
            tot += t[i];
        }
        if(val+mid-lst >= 2*tot){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}