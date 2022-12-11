#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int mnx = 2000, mxx = -2000, mny = 2000, mxy = -2000;
    while(N--){
        int a, b;
        cin >> a >> b;
        mnx = min(mnx, a);
        mxx = max(mxx, a);
        mny = min(mny, b);
        mxy = max(mxy, b);
    }
    if((mxx-mnx)*(mxy-mny) == 0){
        cout << -1 << endl;
    }
    else{
        cout << (mxx-mnx)*(mxy-mny) << endl;
    }
}