#include <bits/stdc++.h>

using namespace std;

int a[200005];
string s, s1;
int use[200005];


bool check(int kol){
    for (int i = 0; i < (int)s.size(); ++i){
        use[i] = 0;
    }
    for (int i = 0; i < kol; ++i){
        use[a[i]] = 1;
    }
    string s2 = "";
    for (int i = 0; i < (int)s.size(); ++i) if (use[i] == 0) s2 += s[i];
    map < int, set < int > > g;
    for (int i = 0; i < (int)s2.size(); ++i){
        if (g.find(s2[i]) != g.end()) g[s2[i]].insert(i);
        else g[s2[i]] = {i};
    }
    int lef = -1;
    for (int i = 0; i < (int)s1.size(); ++i){
        if (g.find(s1[i]) == g.end()) return false;
        auto it = g[s1[i]].upper_bound(lef);
        if (it == g[s1[i]].end()) return false;
        lef = (*it);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> s1;
    for (int i = 0; i < (int)s.size(); ++i) cin >> a[i];
    for (int i = 0; i < (int)s.size(); ++i) a[i]--;
    int l = -1, r = s.size();
    while (r - l > 1){
        int m = (r + l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
    return 0;
}