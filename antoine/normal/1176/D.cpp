#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxX = 2750131 + 9;

int spf[MxX + 9]; // bpf?
vector<int> primes;

void buildSieve() {
    spf[0] = spf[1] = 1;
    for (int i = 2; i <= MxX; ++i) {
        if (spf[i] == 0) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] <= MxX; ++j) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    buildSieve();

    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < 2*n; ++i) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    vector<int> res;
    for(auto it = ms.rbegin(); it != ms.rend(); ++it) {
        const int x = *it;
        if(spf[x] != x) {
            res.push_back(x);
            auto it2 = ms.find(x/spf[x]);
            assert(it2 != ms.end());
            ms.erase(it2);
        }
    }

    for(int x : res) {

        auto it = ms.find(x);
        assert(it != ms.end());
        ms.erase(it);
    }

    assert(primes[0] == 2);
    for(auto it = ms.begin(); it != ms.end(); ++it) {
        const int x = *it;
        assert(spf[x] == x);
        auto it2 = ms.find(primes[x-1]);
        assert(it2 != ms.end());
        ms.erase(it2);

        res.push_back(x);
    }

    assert(res.size()==n);
    for(int x : res)
        cout << x << ' ';

    return 0;
}