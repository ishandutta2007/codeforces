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

int find (int n) {
    int aa = 0;
    while (n > 0) {
        aa += (n % 10);
        n /= 10;
    }
    return aa;
}


int main () {
    int n;
    cin >> n;
    vector <int> ans;
    fop (i,max(n-81,0),n) {
        if (i + find(i) == n) {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    fop (i,0,ans.size()) cout << ans[i] << " \n"[i == ans.size()-1];
}