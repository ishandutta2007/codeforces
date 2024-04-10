#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    srand(time(0));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    string s;
    cin >> s;
    int n = s.size();
    s += s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int t = 1;
        while(i + 1 < s.size() && s[i] != s[i + 1]){
            i++;
            t++;
        }
        ans = max(ans, t);
    }
    cout << min(n, ans) << endl;
}