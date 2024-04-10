#include <bits/stdc++.h>

using namespace std;

int pos[300005];
int rev[300005];
vector < pair < int, int > > out;

void func(int x, int y){
    if (x == y) return;
    int to1 = pos[x], to2 = pos[y];
    pos[x] = to2;
    rev[to2] = x;
    pos[y] = to1;
    rev[to1] = y;
    if (to1 > to2) swap(to1, to2);
    out.push_back({to1, to2});
}


main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        pos[x] = i;
        rev[i] = x;
    }
    for (int i = 1; i <= n; ++i){
        if (pos[i] == i) continue;
        int to = pos[i];
        if (to > n / 2){
            if (i == 1){
                func(1, rev[1]);
                continue;
            }
            func(1, i);
            if (i > n / 2){
                func(i, rev[i]);
                func(rev[1], 1);
            }
            else{
                func(rev[n], i);
                func(i, rev[i]);
                func(1, rev[1]);
            }
        }
        else{
            func(rev[n], i);
            if (i <= n / 2){
                func(i, rev[i]);
            }
            else{
                func(rev[1], i);
                func(i, rev[i]);
                func(1, rev[1]);
            }
        }
    }
    cout << out.size() << '\n';
    for (auto key : out) cout << key.first << " " << key.second << '\n';
    return 0;
}