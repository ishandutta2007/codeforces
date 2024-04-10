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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> used(n);
        queue<int> q0, q1;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                if(q1.empty())
                    used[i] = q1.size()+q0.size()+1;
                else
                    used[i] = q1.front(), q1.pop();
                q0.push(used[i]);
            }else{
                if(q0.empty())
                    used[i] = q1.size()+q0.size()+1;
                else
                    used[i] = q0.front(), q0.pop();
                q1.push(used[i]);
            }
        }
        cout << q1.size()+q0.size() << '\n';
        for(int i = 0; i < n; ++i)
            cout << used[i] << ' ';
        cout << '\n';
    }
    return 0;
}