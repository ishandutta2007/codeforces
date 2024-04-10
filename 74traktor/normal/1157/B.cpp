#include <bits/stdc++.h>

using namespace std;

int a[10];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    for (int i = 1; i <= 9; ++i) cin >> a[i];
    for (int j = 0; j < n; ++j){
        int c = s[j] - '0';
        if (a[c] > c){
            int my_pos = j;
            while (my_pos < n && a[s1[my_pos] - '0'] >= s1[my_pos] - '0') s[my_pos] = char('0' + a[s1[my_pos] - '0']), my_pos++;
            cout << s << '\n';
            return 0;
        }
    }
    cout << s << '\n';
    return 0;
}