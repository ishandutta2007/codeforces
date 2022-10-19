#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 25000 + 5;



int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("a.txt", "r", stdin);
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int check = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[0] || t[i] == s[1]) check = 1;
    }
    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}