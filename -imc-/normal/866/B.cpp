#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct guy {
    li s, a, b;
    
    bool operator<(const guy& g) {
        return abs(a - b) > abs(g.a - g.b);
    }
};

void solve(bool read) {
    int n, S;
    cin >> n >> S;
    
    li sum = 0;
    
    vector<guy> guys(n);
    li a_better_sum = 0, b_better_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> guys[i].s >> guys[i].a >> guys[i].b;
        sum += guys[i].s;
        if (guys[i].a > guys[i].b)
            a_better_sum += guys[i].s;
        else
            b_better_sum += guys[i].s;
    }
    
    li need = (sum + S - 1) / S;
    
    li approx_a = a_better_sum / S;
    
    sort(all(guys));
    
    li best = 0;
    for (li n_a = approx_a - 2; n_a <= approx_a + 2; n_a++) {
        if (n_a < 0 || need - n_a < 0) continue;
        
        li n_b = need - n_a;
        
        li have_a = n_a * S;
        li have_b = n_b * S;
        
        li answer = 0;
        
        for (guy g: guys) {
            if (g.a > g.b) {
                li take = min(have_a, g.s);
                g.s -= take;
                answer += take * g.a;
                have_a -= take;
                take = min(have_b, g.s);
                have_b -= take;
                answer += take * g.b;
            }
            else {
                li take = min(have_b, g.s);
                g.s -= take;
                answer += take * g.b;
                have_b -= take;
                take = min(have_a, g.s);
                have_a -= take;
                answer += take * g.a;
            }
        }
        
        best = max(best, answer);
    }
    
    cout << best << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        //guessed = false;
        solve(false);
        //assert(guessed);
    }
#endif
    
    return 0;
}