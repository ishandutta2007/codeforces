#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef unsigned char uc;
typedef long long ll;

const int MAXSZ = 1e4;

int main() {
    ll sum = 0, n, t, lst = 0;
    cin >> n;
    fr(i, n) {
        cin >> t;
        sum += abs(t - lst);
        lst = t;
    }
    cout << sum;
}