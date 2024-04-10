#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set < int > ans;
    while (1){
        ans.insert(n);
        n += 1;
        int k = n;
        while (n % 10 == 0) n /= 10;
        if (ans.find(n) != ans.end()) break;
    }
    cout << ans.size() << '\n';
    return 0;
}