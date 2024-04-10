#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return (b? gcd(b, a % b) : a);
}

struct Rat {
    long long p, q;

    Rat(long long x): p(x), q(1) {}

    Rat(long long _p, long long _q): p(_p), q(_q) {
        long long g = gcd(p, q);
        p /= g;
        q /= g;
    }

    bool operator<(const Rat &r) const {
        return p * r.q < r.p * q;
    }
};

const int MAXN = 100 * 1000 + 5;
int a[MAXN];
pair<int, int> as[MAXN];
vector< pair<pair<Rat, int>, int> > mul;
vector< pair<pair<int, int>, int> > add[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int k, n, m;
    cin >> k >> n >> m;
    for(int i = 0; i < k; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int t, p, b;
        cin >> t >> p >> b;
        p--;
        if(t == 1)
            as[p] = max(as[p], make_pair(b, i));
        else if(t == 2)
            add[p].push_back(make_pair(make_pair(b, i), t));
        else
            mul.push_back(make_pair(make_pair(Rat(b), i), t));
    }
    for(int i = 0; i < k; i++)
        if(as[i].first > a[i])
            add[i].push_back(make_pair(make_pair(as[i].first - a[i],
                                                 as[i].second), 1));
    for(int i = 0; i < k; i++) {
        sort(add[i].begin(), add[i].end(),
             greater< pair<pair<int, int>, int> >());
        long long sum = a[i];
        for(size_t j = 0; j < add[i].size(); j++) {
            mul.push_back(make_pair(make_pair(Rat(sum + add[i][j].first.first,
                                                  sum), add[i][j].first.second),
                                    add[i][j].second));
            sum += add[i][j].first.first;
        }
    }
    for(size_t i = 0; i < mul.size(); i++)
        mul[i].first.first.p -= mul[i].first.first.q;
    sort(mul.begin(), mul.end(), greater< pair<pair<Rat, int>, int> >());
    m = min(m, (int)mul.size());
    cout << m << '\n';
    for(int t = 1; t < 4; t++)
        for(int i = 0; i < m; i++)
            if(mul[i].second == t)
                cout << mul[i].first.second + 1 << ' ';
    cout << '\n';
    return 0;
}