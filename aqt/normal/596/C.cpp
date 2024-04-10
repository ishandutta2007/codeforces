#include <bits/stdc++.h>

using namespace std;

int N;
map<int, deque<int>> mp;
pair<int, int> arr[100005];
map<pair<int, int>, int> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        arr[i].first = x, arr[i].second = y;
        mp[y-x].push_back(y);
    }
    for(auto i = mp.begin(); i != mp.end(); i++){
        sort(i->second.begin(), i->second.end());
    }
    for(int i = 1; i<=N; i++){
        int c;
        cin >> c;
        if(mp[c].empty()){
            cout << "NO" << "\n";
            return 0;
        }
        int y = mp[c].front();
        mp[c].pop_front();
        int x = y - c;
        pair<int, int> p = {x, y};
        arr[i] = p;
        ans[p] = i;
        if(p.first){
            if(ans[{p.first-1, y}] == 0){
                cout << "NO" << "\n";
                return 0;
            }
        }
        if(p.second){
            if(ans[{x, p.second-1}] == 0){
                cout << "NO" << "\n";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    for(int i = 1; i<=N; i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
}