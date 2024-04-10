#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll v[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll d, i;
    cin >> v[0] >> v[1] >> v[2];
    cout << "First" << endl;
    d = 1e9;
    cout << d << endl;
    cin >> i; v[--i] += d;
    
    d = max(2*v[0]-v[1]-v[2],max(2*v[1]-v[0]-v[2],2*v[2]-v[0]-v[1]));
    cout << d << endl;
    cin >> i; v[--i] += d;

    cout << min(v[i]-v[(i+1)%3],v[i]-v[(i+2)%3]) << endl;
    cin >> i;
    return 0;
}