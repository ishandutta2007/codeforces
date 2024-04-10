#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int n;
    cin >> n;
    lli a[n][n];
    fop (i,0,n) {
        fop (j,0,n) {
            cin >> a[i][j];
        }
    }
    lli aaa=a[0][1]*a[0][2]/a[1][2];
    aaa=sqrt(aaa);
    cout << aaa << ' ';
    fop (i,1,n) cout << a[0][i]/aaa << ' ';
    cout << endl;
}