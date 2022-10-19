#include <bits/stdc++.h>
using namespace std;

int n;
double s;
vector <int> nebo[100000+5];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        nebo[u].push_back(v);
        nebo[v].push_back(u);
    }
    if (n==2) cout << setprecision(10) << fixed << s;
    else {
        int cnt=0;
        for (int i=1; i<=n ;i++){
            if (nebo[i].size()==1) cnt++;
        }
        cout << setprecision(10) << fixed << s/cnt*2;
    }
}