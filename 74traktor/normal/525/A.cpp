#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    multiset < char > Q;
    int ans = 0;
    for (int i = 0; i < 2 * n - 2; i += 2){
        char c = s[i], c1 = s[i + 1];
        Q.insert(c);
        if (c1 <= 'z' && c1 >= 'a'){
            if (Q.find(char('A' + (int)c1 - 'a')) != Q.end()){
                Q.erase(Q.find(char('A' + (int)c1 - 'a')));
            }
            else{
                ans++;
            }
        }
        else{
            if (Q.find(char('a' + (int)c1 - 'A')) != Q.end()){
                Q.erase(Q.find(char('a' + (int)c1 - 'A')));
            }
            else{
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}