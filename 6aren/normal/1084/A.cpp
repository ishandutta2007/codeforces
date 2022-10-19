#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[105];
    long long mini=100000000000000;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int x=1; x<=n; x++){
        long long res=0;
        for (int i=1; i<=n; i++){
            int u, ele;
            u=a[i];
            ele=abs(i-x)+i+x+x+i+abs(i-x)-4;
            ele=ele*u;
            res+=ele;
        }
        //if (x==2) cout << res << endl;
        mini=min(mini, res);
    }
    cout << mini;
}