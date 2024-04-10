#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int N, X, Y; cin >> N >> X >> Y;
        vector<int> b (N); vector<int> ans (N, -1);
        for(int i = 0; i < N; i++) cin >> b[i];
        map<int, vector<int>> loc;
        for(int i = 0; i < N; i++) loc[b[i]].emplace_back(i);
        set<pair<int, int>, greater<pair<int, int>>> freq;
        for(auto t: loc) freq.insert(make_pair((t.second).size(), t.first));
        int in_place = 0;
        while(in_place < X){
            auto last = *freq.begin();
            int pos = loc[last.second].back();
            loc[last.second].pop_back();
            freq.erase(last);
            if(last.first > 1) freq.insert(make_pair(last.first-1, last.second));
            ans[pos] = last.second;
            in_place++;
        }
        int not_present = -1;
        for(int i = 1; i <= N+1; i++){
            if(loc.find(i) == loc.end()){
                not_present = i; break;
            }
        }
        vector<pair<int, int>> shuffle;
        for(int i = 0; i < N; i++){
            if(ans[i] != -1) continue;
            shuffle.emplace_back(make_pair(b[i], i));
        }
        sort(shuffle.begin(), shuffle.end());
        vector<int> reassign ((shuffle).size());
        int shift = (N-X)/2;
        int len = shuffle.size();
        for(int i = 0; i < len; i++) reassign[i] = shuffle[(i+shift)%len].first;
        for(int i = 0; i < len; i++) ans[shuffle[i].second] = reassign[i];
        vector<int> overlap;
        for(int i = 0; i < len; i++){
            if(reassign[i] == shuffle[i].first) overlap.emplace_back(shuffle[i].second);
        }
        if(N-Y < overlap.size()){
            cout << "NO" << '\n';
            continue;
        }
        int reduce = N-Y;
        for(int idx: overlap) ans[idx] = not_present;
        reduce -= overlap.size();
        for(int i = 0; i < N; i++){
            if(reduce == 0) break;
            if(ans[i] != b[i] && ans[i] != not_present){
                ans[i] = not_present;
                reduce--;
            }
        }
        cout << "YES" << '\n';
        for(int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}