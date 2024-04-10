#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<pair<int, int>> pts(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int) s[i].size(); j++){
            pts[i].first += (s[i][j] == 'N');
            pts[i].second += (s[i][j] == 'B');
        }
    }
    pair<int, int> bot_bound = make_pair(-INF, -INF);
    pair<int, int> top_bound = make_pair(INF, INF);
    pair<int, int> opt = make_pair(0, 0);
    int max_diff = INF;
    int min_diff = -INF;
    for(int i = 0; i < n; i++){
        top_bound.first = min(top_bound.first, pts[i].first);
        top_bound.second = min(top_bound.second, pts[i].second);
        bot_bound.first = max(bot_bound.first, pts[i].first);
        bot_bound.second = max(bot_bound.second, pts[i].second);
        max_diff = min(max_diff, pts[i].first - pts[i].second);
        min_diff = max(min_diff, pts[i].first - pts[i].second);
    }
    int ans = INF;
    for(int radius = 5e5; radius >= 0; radius--){
        pair<int, int> top;
        pair<int, int> bot;
        top.first = top_bound.first + radius;
        top.second = top_bound.second + radius;
        bot.first = bot_bound.first - radius;
        bot.second = bot_bound.second - radius;
        int big_diff = max_diff + radius;
        int small_diff = min_diff - radius;
        if(top.first < bot.first) continue;
        if(top.second < bot.second) continue;
        if(small_diff > big_diff) continue;
        if(small_diff > top.first - bot.second) continue;
        if(big_diff < bot.first - top.second) continue;
        if(bot.first - bot.second < small_diff){
            opt.second = bot.second;
            opt.first = bot.second + small_diff;
        }
        else if(bot.first - bot.second > big_diff){
            opt.first = bot.first;
            opt.second = bot.first - big_diff;
        }
        else{
            opt.first = bot.first;
            opt.second = bot.second;
        }
        ans = min(ans, radius);
    }
    cout << ans << '\n';
    if(opt.first <= 0 && opt.second <= 0){
        cout << "NB" << '\n';
    }
    else{
        for(int i = 0; i < opt.first; i++) cout << 'N';
        for(int i = 0; i < opt.second; i++) cout << 'B';
        cout << '\n';
    }
    return 0;
}