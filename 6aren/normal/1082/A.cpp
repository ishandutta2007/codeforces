#include <bits/stdc++.h>
using namespace std;

int main(){
    int ntest;
    cin >> ntest;
    while (ntest--){
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int a=2e9, b=2e9, c=2e9;
        if (y%d==1){
            a=(x-2)/d+1+(y-1)/d;
        }
        if (y%d==n%d){
            b=(n-x-1)/d+1+(n-y)/d;
        }
        if (y%d==x%d){
            c=abs(x-y)/d;
        }
        int res=min(a, min(b, c));
        if(res==2e9) cout << -1 << endl;
        else cout << res << endl;
    }
}