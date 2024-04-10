#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;
const ll inf = 1e18;

pii p[3];
int ord[3];

ll distance(pii a, pii b) {
    return ll(abs(a.first - b.first)) + ll(abs(a.second - b.second));
}

int get_median(vector<int> vec) {
    sort(vec.begin(), vec.end());
    return vec[vec.size()/2];
}

void add_path(vector<pair<pii, pii>> &path, pii a, pii b) {
    if(a == b)
        return;
    if(a.first == b.first || a.second == b.second) {
        path.push_back({a, b});
        return;
    }
    pii mid = {a.first, b.second};
    path.push_back({a, mid});
    path.push_back({mid, b});
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for(int i = 0; i < 3; i++) {
        cin >> p[i].first >> p[i].second;
    }    
    iota(ord, ord+3, 0);

    vector<pair<pii, pii>> path;
    int X = get_median({p[0].first, p[1].first, p[2].first});
    int Y = get_median({p[0].second, p[1].second, p[2].second});
    for(int i = 0; i < 3; i++) {
        add_path(path, {X, Y}, p[i]);
    }
    cout << path.size() << "\n";
    for(auto p : path) {
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << "\n";
    }
    return 0;
}