#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

#define pb push_back

vector <bool> e;
set <int> primes;
map <int, int> num_of_primes;


bool is_prime(int x) {
    return primes.find(x) != primes.end();
}

void go() {
    e.assign(3e6, true);
    e[0] = false;
    e[1] = false;
    for (long long i = 2; i < 3e6; i++) {
        if (e[i] == false) {
            continue;
        }
        for (long long j = i * i; j < 3e6; j += i) {
            e[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i < 3e6; i++) {
        if (e[i]) {
            num_of_primes[i] = cnt + 1;
            cnt++;
            primes.insert(i);
        }
    }
}

int ld(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return x / i;
        }
    }
    return 1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(2 * n);
    for (auto &c : a) {
        cin >> c;
    }
    go();
    sort(a.rbegin(), a.rend());
    vector <bool> usd(2 * n);
    vector <int> ans;
    vector <vector<int>> gist(3e6);
    for (int i = 0; i < 2 * n; i++) {
        gist[a[i]].pb(i);
    }
    for (int i = 0; i < 2 * n; i++) {
        if (usd[i]) {
            continue;
        }
        if (is_prime(a[i])) {
            int need = num_of_primes[a[i]];
            usd[i] = true;
            usd[gist[need].back()] = true;
            gist[need].pop_back();
            ans.pb(need);
        }
        else {
            int need = ld(a[i]);
            usd[i] = true;
            usd[gist[need].back()] = true;
            gist[need].pop_back();
            ans.pb(a[i]);
        }
    }
    for (auto &c : ans) {
        cout << c << " ";
    }
    return 0;
}