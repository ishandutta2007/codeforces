#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> st;
int par[200005], sz[200005], cnt[200005], lst[200005];
vector<int> graph[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i= 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        if(a < b){
            swap(a, b);
        }
        graph[a].push_back(b);
    }
    for(int i= 1; i<=N; i++){
        par[i] = i;
        sz[i] = 1;
        for(int e : graph[i]){
            int r = getrt(e);
            if(lst[r] != i){
                lst[r] = i;
                cnt[r] = 0;
            }
            cnt[r]++;
        }
        vector<int> v;
        for(int n : st){
            v.push_back(n);
            if(sz[n] != cnt[n] || lst[n] != i){
                sz[i] += sz[n];
                par[n] = i;
            }
        }
        for(int n : v){
            if(getrt(n) == i){
                st.erase(n);
            }
        }
        st.insert(i);
    }
    vector<int> ans;
    for(int n : st){
        ans.push_back(sz[n]);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int n : ans){
        cout << n << " ";
    }
}