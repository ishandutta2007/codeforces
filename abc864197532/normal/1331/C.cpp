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
#define X first
#define Y second
 
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    cin >> a;
    if (__builtin_popcount(a & 17) == 1) a ^= 17;
    if (__builtin_popcount(a & 12) == 1) a ^= 12;
    cout << a << endl;
}