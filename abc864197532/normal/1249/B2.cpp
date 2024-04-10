#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n+1],is[n+1];
        fop (i,1,n+1) cin >> x[i] , is[i]=false;
        fop (i,1,n+1) {
            if (is[i]) continue;
            set <int> nums;
            int k=x[i],ans=0;
            while (!nums.count(k)) {
                nums.insert(k);
                k=x[k];
                ans++;
            }
            for (auto a : nums) {
                is[a]=ans;
            }
        }
        fop (i,1,n+1) cout << is[i] << " \n" [i==n];
    }
}