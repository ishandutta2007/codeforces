#include <bits/stdc++.h>

using namespace std;

string s[200];

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string ans;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> ans;
    int mincnt = 0, maxcnt = 0;
    for (int i = 0; i < n; i++){
        if (s[i].size() < ans.size())
            mincnt ++;
        if (s[i].size() <= ans.size())
            maxcnt ++;
    }
    maxcnt --;
    cout << (mincnt + 5 * (mincnt / k)) + 1 << " " << maxcnt + 5 * (maxcnt / k) + 1 << endl;
    return 0;
}