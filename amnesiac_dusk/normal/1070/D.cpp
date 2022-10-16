#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
typedef long double f80;
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5;
int a[N];
signed main(){
    IO;
    //freopen("inp.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    bool lft = 0;
    fr(i, 1, n){
        cin >> a[i];
    }
    fr(i, 1, n){
        ans += (a[i] / k);
        if(a[i] < k && lft){
            a[i] = 0;
            ans++;
        }
        a[i + 1] += a[i] % k;
        if(a[i] % k)
            lft = 1;
        else
            lft = 0;
    }
    if(a[n + 1])
        ans++;
    cout << ans;
    return 0;
}