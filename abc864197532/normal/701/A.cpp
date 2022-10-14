#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main() {
    int n;
    cin >> n;
    pii a[n];
    fop (i,0,n) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a,a+n);
    fop (i,0,n/2) {
        cout << a[i].second << ' ' << a[n-i-1].second << endl;
    }
}