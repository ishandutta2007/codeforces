#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
        int s, n;
        cin >> s >> n;
        pair<int,int>t[n];
        rep(i, n) cin >> t[i].first >> t[i].second;
        sort(t, t+n);
        rep(i, n) if(s>t[i].first) s+=t[i].second; else {
                cout << "NO";
                return 0;
        }
        cout << "YES";
}