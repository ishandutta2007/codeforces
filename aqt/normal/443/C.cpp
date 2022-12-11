#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    map<string, vector<int>> mp;
    vector<char> p = {'R', 'B', 'G', 'Y', 'W', '1', '2', '3', '4', '5'};
    set<string> st;
    while(N--){
        string s;
        cin >> s;
        st.insert(s);
    }
    N = st.size();
    int ans = 10;
    for(int m = 0; m<1<<10; m++){
        for(int k = 0; k<10; k++){
            if((m>>k)&1){
                for(auto s : st){
                    if(s[0] == p[k] || s[1] == p[k]){
                        mp[s].push_back(k);
                    }
                }
            }
        }
        bool b = 1;
        for(auto s1 : st){
            for(auto s2 : st){
                if(s1 != s2 && mp[s1] == mp[s2]){
                    b = 0;
                }
            }
        }
        if(b){
            ans = min(ans, __builtin_popcount(m));
        }
        mp.clear();
    }
    cout << ans << endl;
}