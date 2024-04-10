#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> m;
        for(int i = 0; i < n; ++i)
            m[s[i]]++;
        char ans;
        if(m['R'] >= m['S'] && m['R'] >= m['P'])
            ans = 'P';
        else if(m['S'] >= m['P'])
            ans = 'R';
        else
            ans = 'S';
        for(int i = 0; i < n; ++i)
            cout << ans;
        cout << '\n';
    }
	return 0;
}