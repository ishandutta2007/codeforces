#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100000+5;
const int MOD=998244353;

ll n, a[N], d[4][N];
string s;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    cout << min(a[n-1]-a[1], a[n-2]-a[0]);
    return 0;
}