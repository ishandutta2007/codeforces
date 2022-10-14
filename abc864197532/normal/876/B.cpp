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


int main () {
    int n,k,m,tmp;
    cin >> n >> k >> m;
    int a[n];
    int m1[m];
    fop (i,0,m) m1[i] = 0;
    fop (i,0,n) {
        cin >> tmp;
        m1[tmp % m]++;
        a[i] = tmp;
    }
    fop (i,0,m) {
        if (m1[i] >= k) {
            cout << "Yes" << endl;
            fop (j,0,n) {
                if (a[j] % m == i) {
                    cout << a[j] << ' ';
                    k--;
                } if (!k) {
                    cout << endl;
                    break;
                }
            }
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}