#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cout << fixed << setprecision(10);
    string str;
    cin >> str;
    int l = str.length();
    
    vector<vector<string>> sor(26);

    for(int i = 0; i < l; i ++) {
        string cur = str;
        for(int j = 0; j < l; j ++) {
            cur[j] = str[(j+i)%l];
        }
        sor[str[i]-'a'].push_back(cur);
    }
    ld res = 0;
    for(int c = 0; c < 26; c ++) {
        ld prob = 0;
        int sz = sor[c].size();
        for(int i = 0; i < l; i ++) {
            vector<int> cnt(26);
            for(int j = 0; j < sz; j ++) {
                cnt[sor[c][j][i]-'a'] ++;
            }
            ld cur = 0;
            for(int j = 0; j < 26; j ++) {
                if(cnt[j] == 1) {
                    cur ++;
                }
            }
            cur /= sz;
            prob = max(prob,cur);
        }
        res += prob * (ld)(sor[c].size()) / (ld)(l);
    }
    cout << res;
    return 0;
}