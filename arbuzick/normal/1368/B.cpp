#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int a = 1;
    vector<int> a1(10, 1);
    while(a < k){
        for(int i = 0; i < 10; ++i){
            a /= a1[i];
            a1[i]++;
            a *= a1[i];
            if(a >= k)
                break;
        }
    }
    string s = "codeforces";
    for(int i = 0; i < 10; ++i)
        while(a1[i]--)
            cout << s[i];
    cout << '\n';
    return 0;
}