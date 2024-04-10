#include <bits/stdc++.h>

using namespace std;

#define int long long
unordered_map < int, int > answ;

int gcd(int a, int b){
    while (a > 0 && b > 0){
        int tt = a % b;
        a = b;
        b = tt;
    }
    return a + b;
}

main(){
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    vector < int > QQ = {
    0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401,
    };
    for (int st = 1; st <= 25; ++st) answ[(1<<st) - 1] = QQ[st - 1];
    for (int i = 1; i <= q; ++i){
        int x;
        cin >> x;
        int st = 1, p = 1;
        while (st <= x) st *= 2, p++;
        if (x == st - 1){
            cout << answ[x] << '\n';
        }
        else cout << st - 1 << '\n';
    }
    return 0;
}