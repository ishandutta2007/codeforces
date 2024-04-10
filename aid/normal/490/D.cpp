#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a[2][2], del2[2], del3[2], p2[2], p3[2];
vector<long long> fact[2];

void factorize(long long x, int t) {
    while(!(x % 2)) {
        p2[t]++;
        x /= 2;
    }
    while(!(x % 3)) {
        p3[t]++;
        x /= 3;
    }
    for(long long i = 5; i * i <= x; i++)
        while(!(x % i)) {
            fact[t].push_back(i);
            x /= i;
        }
    if(x != 1)
        fact[t].push_back(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    factorize(a[0][0], 0);
    factorize(a[0][1], 0);
    factorize(a[1][0], 1);
    factorize(a[1][1], 1);
    sort(fact[0].begin(), fact[0].end());
    sort(fact[1].begin(), fact[1].end());
    if(fact[0].size() != fact[1].size()) {
        cout << -1 << '\n';
        return 0;
    }
    for(size_t i = 0; i < fact[0].size(); i++)
        if(fact[0][i] != fact[1][i]) {
            cout << -1 << '\n';
            return 0;
        }
    if(p3[0] > p3[1]) {
        del3[0] += p3[0] - p3[1];
        p2[0] += p3[0] - p3[1];
    }
    else {
        del3[1] += p3[1] - p3[0];
        p2[1] += p3[1] - p3[0];
    }
    if(p2[0] > p2[1])
        del2[0] += p2[0] - p2[1];
    else
        del2[1] += p2[1] - p2[0];
    for(long long i = 0; i < del3[0]; i++)
        if(!(a[0][0] % 3)) {
            a[0][0] /= 3;
            a[0][0] *= 2;
        }
        else {
            a[0][1] /= 3;
            a[0][1] *= 2;
        }
    for(long long i = 0; i < del3[1]; i++)
        if(!(a[1][0] % 3)) {
            a[1][0] /= 3;
            a[1][0] *= 2;
        }
        else {
            a[1][1] /= 3;
            a[1][1] *= 2;
        }
    for(long long i = 0; i < del2[0]; i++)
        if(!(a[0][0] % 2))
            a[0][0] /= 2;
        else
            a[0][1] /= 2;
    for(long long i = 0; i < del2[1]; i++)
        if(!(a[1][0] % 2))
            a[1][0] /= 2;
        else
            a[1][1] /= 2;
    cout << del2[0] + del2[1] + del3[0] + del3[1] << '\n'
         << a[0][0] << ' ' << a[0][1] << '\n'
         << a[1][0] << ' ' << a[1][1] << '\n';
    return 0;
}