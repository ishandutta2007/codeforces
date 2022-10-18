#include <bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int kol = 0;
    vector < char > q;
    for (auto c : s){
        if ((int)q.size() > 0 && q.back() == c){
            kol++;
            q.pop_back();
        }
        else q.push_back(c);
    }
    if (kol % 2 == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}