#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        int bef = -1;
        int inp;
        for(int i = 0; i < n; i++){
            cin >> inp;
            if(bef == inp) continue;
            a.push_back(inp);
            bef = inp;
        }
        if(a.size() == 1) cout << 0 << endl;
        else{
            vector<int> cnt(n + 1);
            for(int i = 0; i < n + 1; i++) cnt.at(i) = n + 1;
            for(int i = 0; i < a.size(); i++){
                int pos = a.at(i);
                if(cnt.at(pos) == n + 1) cnt.at(pos) = 1;
                else cnt.at(pos)++;
            }
            cnt.at(a.at(0))--;
            cnt.at(a.at(a.size() - 1))--;
            int ans = n + 1;
            for(int i = 0; i < n + 1; i++){
                ans = min(ans, cnt.at(i) + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}