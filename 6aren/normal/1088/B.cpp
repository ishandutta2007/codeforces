#include <bits/stdc++.h>
using namespace std;
set <int> P;
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int x;
        cin >> x;
        P.insert(x);
    }
    int mmr=0;
    int cnt=0;
    set <int> :: iterator it;
    for (it=P.begin();it!=P.end();it++){
        int u=*it;
        cout << u-mmr << endl;
        mmr=u;
        cnt++;
        if (cnt==m) break;
    }
    for (int i=cnt+1;i<=m;i++) cout << 0 << endl;
}