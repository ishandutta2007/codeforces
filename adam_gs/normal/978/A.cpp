#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'
#define len(a) a.size()
#define cs(a) cout << "Case #" << a << ": "
#define lst(a) a[len(a)-1]
#define tests(a) cin >> a; while(a--)

int p[1000];

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    vector <int>T;
    for (int i = n-1; i>=0; --i) {
        if (p[tab[i]-1]==0) {
            T.push_back(tab[i]);
        }
        p[tab[i]-1]=1;
    }
    cout << len(T);
    nl;
    for (int i = len(T)-1; i>=0; --i) {
        cout << T[i] << " ";
    }
}