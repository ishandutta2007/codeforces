#include <bits/stdc++.h>

using namespace std;

int N, K;
set<int> st;
int ans[200005];
int pos[200005];
int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i =1 ; i<=N; i++){
        st.insert(i);
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    int X = 1;
    for(int i = N; i>0; i--){
        if(st.count(pos[i])){
            X++;
            st.erase(pos[i]);
            ans[pos[i]] = X%2+1;
            int C = K;
            while(st.size() && *st.rbegin() > pos[i] && C--){
                ans[*st.upper_bound(pos[i])] = X%2+1;
                st.erase(st.upper_bound(pos[i]));
            }
            C = K;
            while(st.size() && *st.begin() < pos[i] && C--){
                ans[*(--st.lower_bound(pos[i]))] = X%2+1;
                st.erase(--st.lower_bound(pos[i]));
            }
        }
    }
    for(int i =1 ; i<=N; i++){
        cout << ans[i];
    }
}