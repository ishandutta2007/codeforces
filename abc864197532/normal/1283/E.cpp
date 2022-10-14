#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    int minn = 0;
    int aa[n+2];
    fop (i,0,n+2) aa[i] = 0;
    fop (i,0,n) {
        aa[a[i]]++;
    }
    fop (i,0,n+2) {
        if (aa[i]) {
            minn++;
            i += 2;
        }
    }
    int maxx = 0;
    fop (i,1,n+1) {
        if (aa[i] > 2) {
            aa[i] -= 2;
            aa[i-1]++;
            aa[i+1]++;
        } else if (aa[i]) {
            if (aa[i-1] == 0) {
                aa[i]--;
                aa[i-1]++;
            } else {
                aa[i]--;
                aa[i+1]++;
            }
        } 
    }
    fop (i,0,n+2) if (aa[i]) maxx++;
    cout << minn << ' ' << maxx << endl;
}