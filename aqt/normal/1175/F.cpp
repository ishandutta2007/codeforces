#include <bits/stdc++.h>

using namespace std;

int N;
int arr[300005];
int pre[300005];
int lst[300005];
int BIT[300005];
vector<pair<int, int>> upd, qu;
set<int> st;

void add(int p){
    for(int i= p; i<=N; i+=i&-i){
        BIT[i]++;
    }
}

int sum(int p){
    int ret = 0;
    p = min(N, p);
    for(int i = p; i>0; i-=i&-i){
        ret += BIT[i];
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        lst[i] = max(lst[i-1], pre[arr[i]]);
        pre[arr[i]] = i;
        upd.push_back({i-lst[i], i});
        qu.push_back({arr[i], i});
    }
    sort(upd.begin(), upd.end(), greater<pair<int, int>>());
    sort(qu.begin(), qu.end(), greater<pair<int, int>>());
    long long ans = 0;
    int idx = 0;
    st.insert(0), st.insert(N+1);
    for(auto p : qu){
        //cout << p.first << " " << p.second << endl;
        while(idx < N && upd[idx].first >= p.first){
            //cout << "add: " << upd[idx].second << endl;
            add(upd[idx++].second);
        }
        //cout << min(*st.upper_bound(p.second) - 1, p.second + p.first - 1) << " "
        //<< max(*(--st.lower_bound(p.second)) + p.first - 1, p.second-1) << endl;
        int ret = sum(min(*st.upper_bound(p.second) - 1, p.second + p.first - 1));
        ret -= sum(max(*(--st.lower_bound(p.second)) + p.first - 1, p.second-1));
        ret = max(0, ret);
        ans += ret;
        //cout << ret << endl;
        st.insert(p.second);
    }
    cout << ans << "\n";
}