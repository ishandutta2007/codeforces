#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    vector < pair < int, char > > G;
    int hp = 1;
    int tmp = 0;
    for (int i = 1; i < n; ++i){
        if (s[i] == s[i - 1])
            hp++;
        else{
            G.push_back({hp, s[i - 1]});
            if (s[i - 1] == 'G'){
                ans = max(ans, hp);
                tmp++;
            }
            hp = 1;
        }
    }
    G.push_back({hp, s[n - 1]});
    if (s[n - 1] == 'G'){
        ans = max(ans, hp);
        tmp++;
    }
    for (int i = 0; i < G.size() - 1; ++i){
        if (G[i].second == 'G'){
            if (G[i + 1].first == 1){
                if (i == G.size() - 2){
                    if (tmp > 1)
                        ans = max(ans, G[i].first + 1);
                    continue;
                }
                if (tmp == 2){
                    ans = max(ans, G[i].first + G[i + 2].first);
                }
                else{
                    ans = max(ans, G[i].first + G[i + 2].first + 1);
                }
            }
            else{
                if (tmp > 1)
                    ans = max(ans, G[i].first + 1);
            }
        }
    }
    if (G[G.size() - 1].second == 'G' && tmp > 1)
        ans = max(ans, G[G.size() - 1].first + 1);
    cout << ans << endl;
    return 0;
}