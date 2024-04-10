#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
ll n, k;
int l[maxn], r[maxn];
int a[maxn], b[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        a[i] = l[i];
        b[i] = r[i];
    }
    sort(a, a + n);
    sort(b, b + n);

    int L = a[n/2], R = b[n/2];
    int res = -1;
    while(L<=R){
        int mid = (L + R)/2;
        int m = 0;
        int le = 0, ri = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(r[i] < mid) {
                sum += l[i];
                le++;
            }else if(l[i] > mid) {
                sum += l[i];
                ri++;
            } else {
                a[m++] = l[i];
                sum += l[i];
            }
        }
        sort(a, a + m);
        while(ri < (n + 1)/2) {
            sum -= a[m-1];
            sum += mid;
            m--;
            ri++;
        }
        if(sum <= k) {
            res = mid;
            L = mid+1;
        }else {
            R = mid-1;
        }
    }
    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}