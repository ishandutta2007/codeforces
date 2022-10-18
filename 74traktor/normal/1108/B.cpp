#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, imax = -1;
    cin >> n;
    multiset < int > Q;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        imax = max(imax, x);
        Q.insert(x);
    }
    cout << imax << " ";
    for (int i = 1; i * i <= imax; ++i){
        if (imax % i == 0){
            Q.erase(Q.find(i));
            if (i * i != imax) Q.erase(Q.find(imax / i));
        }
    }
    cout << (*Q.rbegin()) << endl;
    return 0;
}