#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int mod = 1000000007;

map <int, int> factors;

vector <pair <int, int> > all;

vector <int> pref;
vector <int> suf;

int pow(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1ll * a * pow(a, b - 1)) % mod;
    else {
        int aux = pow(a, b >> 1);
        return (1ll * aux * aux) % mod;
    }
}

int compute(int a, int n, int power) {
    return pow(a, (((n * (n + 1ll) / 2) % (mod - 1)) * power) % (mod - 1));
}

int main()
{
    int m = 0;
    cin >> m;

    int val;
    while (m --) {
        cin >> val;
        ++ factors[val];
    }

    all.push_back(make_pair(0, 0));
    for (auto it: factors)
        all.push_back(it);
    all.push_back(make_pair(0, 0));

    int n = all.size();

    pref.resize(n);
    suf.resize(n);

    pref[0] = 1;
    for (int i = 1; i < n; ++ i)
        pref[i] = (pref[i - 1] * (all[i].second + 1ll)) % (mod - 1);

    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; -- i)
        suf[i] = (suf[i + 1] * (all[i].second + 1ll)) % (mod - 1);


    int ans = 1;
    for (int i = 1; i < n - 1; ++ i)
        ans = (1ll * ans * compute(all[i].first, all[i].second, (1ll * pref[i - 1] * suf[i + 1]) % (mod - 1))) % mod;

    cout << ans << '\n';
    return 0;
}