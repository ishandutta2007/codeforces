#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        vector<int> o, z;
        o.resize(N+1), z.resize(N+1);
        for(int i = 1; i<=N; i++){
            int n, t;
            cin >> n >> t;
            if(t){
                o[n]++;
            }
            else{
                z[n]++;
            }
        }
        set<int> st;
        vector<pair<int, int>> v;
        for(int i = 0; i<=N; i++){
            v.push_back({o[i], z[i]+o[i]});
            st.insert(-i);
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int ans1 = 0, ans2 = 0;
        for(auto p : v){
            int n = *st.lower_bound(-p.second);
            ans1 += -n, ans2 += min(-n, p.first);
            if(n == 0){
                continue;
            }
            st.erase(n);
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}