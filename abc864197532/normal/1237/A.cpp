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
    int x[n],tmp=0;
    fop (i,0,n) {
        cin >> x[i];
        tmp += abs(x[i] % 2);
    }
    tmp /= 2;
    fop (i,0,n) {
        if (x[i] % 2) {
            if (tmp) {
                tmp--;
                cout << (x[i]-1)/2+1 << endl;
            } else {
                cout << (x[i]-1)/2 << endl;
            }
        } else {
            cout << x[i] / 2 << endl;
        }
    }
}