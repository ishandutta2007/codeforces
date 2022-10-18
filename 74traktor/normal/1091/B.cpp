#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int g[1002][2];
multiset < pair < int, int > > use;
multiset < pair < int, int > > isi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> g[i][0] >> g[i][1];
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        use.insert({x, y});
    }
    for (auto key : use){
        bool f = true;
        isi = use;
        x = g[1][0] + key.X, y = g[1][1] + key.Y;
        for (int i = 2; i <= n; ++i){
            if (isi.find({x - g[i][0], y - g[i][1]}) == isi.end()){f = false; break;}
            isi.erase(isi.find({x - g[i][0], y - g[i][1]}));
        }
        if (f){
            cout << x << " " << y << '\n';
            return 0;
        }
    }
    return 0;
}