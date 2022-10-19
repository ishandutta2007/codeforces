#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200000+5;
const int MOD=998244353;

int n, a[2][N], nexti[N];
string s;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[1][i] >> a[0][i];
    }
    if (n==3){
        cout << 1 << " " << 2 << " " << 3 << endl;
        return 0;
    }
    for (int i=1; i<=n; i++){
        if (a[1][a[1][i]]==a[0][i] || a[0][a[1][i]]==a[0][i]){
            nexti[i]=a[1][i];
        } else nexti[i]=a[0][i];
    }
    cout << 1 << " ";
    int cur=1;
    n--;
    while (n--){
        cout << nexti[cur] << " ";
        cur=nexti[cur];
    }
    return 0;
}