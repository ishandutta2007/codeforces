#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 7
bool nums[MAXN][MAXN];

int main () {
    int n, m;
    cin >> n >> m;
    if (n <= 6) {
        cout << m << endl;
        return 0;
    }
    fop (i,0,MAXN) fop (j,0,MAXN) nums[i][j] = false;
    fop (i,0,m) {
        int a, b;
        cin >> a >> b;
        nums[a-1][b-1] = true;
        nums[b-1][a-1] = true;
    }
    int aa = INT_MAX;
    fop (i,0,n) {
        fop (j,i+1,n) {
            int aaa = 0;
            fop (k,0,n) {
                if (nums[i][k] and nums[j][k]) aaa++;
            }
            aa = min(aa, aaa);
        }
    }
    cout << m - aa << endl;
}