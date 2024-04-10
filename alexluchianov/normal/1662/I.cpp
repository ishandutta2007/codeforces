#include <bits/stdc++.h>

using namespace std;

#define int long long

struct event {
    int tip, loc, pop; // 1 - hut, 2 - shop
};

bool cmp1(event& a, event& b) {
    if(a.loc == b.loc) return a.tip < b.tip;
    return a.loc < b.loc;
}

vector<event> events;

struct grad {
    int tip, loc, pop; // +1 = add, -1 = sub
};

bool cmp2(grad& a, grad &b) {
    if(a.loc == b.loc) return a.tip < b.tip;
    return a.loc < b.loc;
}

int64_t solve(vector<event> cnt) {
    /* for(auto c : cnt) {
        cerr << "C" << c.tip << " " << c.loc << " " << c.pop << endl;
    }
    cerr << endl; */

    vector<grad> gradual;
    int l = cnt[0].loc;
    int r = cnt[cnt.size() - 1].loc;

    for(int i = 1; i < cnt.size() - 1; i++) {
        // cerr << i << ": ";
        event hut = cnt[i];

        // cerr << hut.tip << " " << hut.loc << " " << hut.pop << endl;

        if(hut.loc == l || hut.loc == r) continue;
        assert(l < hut.loc && hut.loc < r);
        // cerr << "HUT -> " << hut.pop << endl;

        int enter_loc = hut.loc - (r - hut.loc - 1);
        enter_loc = max(enter_loc, l + 1);
        // while(abs(hut.loc - enter_loc) >= abs(hut.loc - l)) enter_loc += 1;

        int exit_loc = hut.loc + (hut.loc - l - 1);
        exit_loc = min(exit_loc, r - 1);
        // while(abs(hut.loc - exit_loc) >= abs(hut.loc - exit_loc)) exit_loc -= 1;

        gradual.push_back({+1, enter_loc, hut.pop});
        gradual.push_back({-1, exit_loc, hut.pop});
    }

    sort(gradual.begin(), gradual.end(), cmp2);
    /* for(auto g : gradual) {
        cerr << g.tip << " " << g.loc << " " << g.pop << endl;
    }
    cerr << endl; */

    int64_t best = 0, s = 0;

    for(auto g : gradual) {
        s = 1LL * s + 1LL * g.tip * g.pop;
        best = max(best, s);
    }

    return best;
}

int32_t main() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        events.push_back({1, i * 1000, p});
    }

    events.push_back({2, (int)-1e16, 0});
    events.push_back({2, (int)+1e16, 0});
    for(int i = 0; i < m; i++) {
        int l; cin >> l;
        events.push_back({2, 10 * l, 0});
    }

    sort(events.begin(), events.end(), cmp1);

    vector<event> cnt = {events[0]};
    int64_t ans = 0;
    for(int i = 1; i < events.size(); i++) {
        cnt.push_back(events[i]);
        if(events[i].tip == 2) {
            ans = max(ans, solve(cnt));
            cnt = {events[i]};
        }
    }

    cout << ans << endl;
}