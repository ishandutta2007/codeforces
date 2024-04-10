#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 200011;

struct analyzer {
    ll sum = 0;
    int base = maxN;
    ll up[maxN * 2], down[maxN * 2];

    void init() {
        sum = 0;
        base = maxN;
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
    }

    void insert_up(ll value) {
        sum -= 2LL * up[base];
        sum += 2LL * down[base - 1];
        base--;

        up[base + 1] += value;
        sum -= value;
    }

    void insert_down(ll value) {
        sum -= 2LL * down[base];
        sum += 2LL * up[base + 1];
        base++;

        down[base - 1] += value;
        sum -= value;
    }

    void remove_up(ll value) {
        up[base] -= value;
        sum -= value;
    }

    void remove_down(ll value) {
        down[base] -= value;
        sum -= value;
    }

};

ll m, x;
int n;
ll a[maxN], b[maxN];
vector< pair< ll, int> > order;
int answer[maxN];
analyzer graph;

void remove_duplicates(vector< pair<ll, int> >& order) {
    auto aux = order;
    vector< pair<ll, int> > plus, minus;
    order.clear();

    int j;
    for (int i = 0; i < aux.size(); i = j) {
        plus.clear();
        minus.clear();

        for (j = i; j < aux.size() && aux[j].first == aux[i].first; j++){
            if (aux[j].second < 0)
                minus.pb(aux[j]);
            else
                plus.pb(aux[j]);
        }

        /*
        for (auto e: minus) cerr << e.first << ' '; cerr << '\n';
        for (auto e: plus) cerr << e.first << ' '; cerr << "\n";
        cerr << "\n";
        */

        while (!minus.empty() && !plus.empty()) {
            answer[plus.back().second] = -minus.back().second;
            minus.pop_back();
            plus.pop_back();
        }

        while (!minus.empty()) {
            order.pb(minus.back());
            minus.pop_back();
        }

        while (!plus.empty()) {
            order.pb(plus.back());
            plus.pop_back();
        }
    }
}

void find_best() {
    int cnt = order.size();
    pair<ll, int> best = mp(1LL << 60, -1);

    for (int i = 0; i < cnt; i++) 
        order.pb(mp(order[i].first + m, order[i].second));

    for (int i = 2 * cnt - 1; i >= 0; i--) {
        if (i < cnt) {
            if (order[i + cnt].second < 0)
                graph.remove_down(order[i + cnt].first);
            else
                graph.remove_up(order[i + cnt].first);
        }

        if (order[i].second < 0) 
            graph.insert_down(order[i].first);
        else 
            graph.insert_up(order[i].first);

        if (i < cnt)
            best = min(best, mp(graph.sum, i));
    }

    vector<int> minus, plus;
    minus.clear();
    plus.clear();
    for (int i = 0; i < cnt; i++) {
        if (order[best.second + i].second < 0)
            minus.pb(-order[best.second + i].second);
        else
            plus.pb(order[best.second + i].second);
    }

    for (int i = 0; 2 * i < cnt; i++) {
        answer[plus[i]] = minus[i];
    }

    if (cnt == 0) best.first = 0;

    printf("%lld\n", best.first);
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        order.pb(mp(a[i], i));
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        order.pb(mp(b[i], -i));
    }

    sort(order.begin(), order.end());
    remove_duplicates(order);
    find_best();


    return 0;
}