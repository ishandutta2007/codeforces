#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, a, b;
    cin >> k >> a >> b;
    if(a < b) { swap(a,b); }
    if((a < k) || (b < k && (a%k != 0))) {
        cout << "-1\n";
    } else {
    cout << (a/k + b/k) << "\n";
    }
    return 0;
}