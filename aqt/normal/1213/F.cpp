#include <bits/stdc++.h>

using namespace std;

int N, K;
int p[200005], q[200005];
char ans[200005];
set<int> st;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i =1; i<=N; i++){
        cin >> p[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> q[i];
    }
    int cnt = 0;
    int lst = 0;
    for(int i = 1; i<=N; i++){
        st.insert(p[i]);
        st.insert(q[i]);
        if((int) (st.size()) == i-lst){
            for(int n : st){
                ans[n] = (char) ('a' + min(cnt, K-1));
            }
            cnt++;
            lst = i;
            st.clear();
        }
    }
    if(cnt < K){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        for(int i = 1; i <= N; i++){
            cout << ans[i];
        }
    }
}