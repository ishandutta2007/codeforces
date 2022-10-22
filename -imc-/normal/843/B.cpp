#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

map<int, pair<int, int>> cache;
int x;

vector<pair<int, int>> ans = { { 97, -1 }, { 58, 5 }, { 16, 2 }, { 81, 1 }, { 79, 4 } };

int nq = 0;

int my_rand() {
    int x = (rand() << 16) + rand();
    return abs(x);
}

pair<int, int> query(int ind) {
    if (ind == -1) return make_pair(-1, -1);
    if (cache.count(ind)) return cache[ind];
    
    if (nq >= 1950) {
        cout << "! -1\n";
        exit(0);
    }
    
    nq++;
    assert(nq < 2000);
    cout << "? " << ind << endl;
#if 1
    int value, next;
    cin >> value >> next;
#else
    int value = ans[ind - 1].first, next = ans[ind - 1].second;
#endif
    
    if (value == x) {
        cout << "! " << x << endl;
        exit(0);
    }
    
    return (cache[ind] = make_pair(value, next));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    srand(time(0));
    
    int n, start;
    cin >> n >> start >> x;
    
    const int MAGIC = 1000;
    
    int best_start = start;
    int best_value = query(best_start).first;
    
    if (best_value > x) {
        cout << "! " << best_value << endl;
        return 0;
    }
    
    int sol_hash = 0;
    for (int i = 0; i < MAGIC; i++) {
        int ind = my_rand() % n + 1;
        auto it = query(ind);
        
        sol_hash += ind;
        
        if (my_rand() % 10 == 100)
            srand(time(0) ^ sol_hash);
        
        if (it.first < x && it.first > best_value) {
            best_start = ind;
            best_value = it.first;
            sol_hash ^= best_value;
        }
    }
    
    assert(best_value < x);
    while (best_start != -1 && query(best_start).first < x) {
        best_start = query(best_start).second;
    }
    
    if (best_start == -1)
        cout << "! " << -1 << endl;
    else
        cout << "! " << query(best_start).first << endl;
    
    
    return 0;
}