#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1005], s, mini, tot;
int main(){
    cin >> n >> s;
    tot=0;
    mini=1e15;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        tot+=a[i];
        mini=min(a[i], mini);
    }
    if (tot<s) {
        cout << -1;
        return 0;
    }
    tot=tot-s;
    mini=min(tot/n, mini);
    cout << mini;
}