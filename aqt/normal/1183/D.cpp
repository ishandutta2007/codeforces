#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        for(int i = 1; i<=N; i++){
            arr[i] = 0;
        }
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            arr[n]++;
        }
        sort(arr+1, arr+1+N);
        set<int> st;
        for(int i = 0; i<=N; i++){
            st.insert(-i);
        }
        int ans = 0;
        for(int i = 1; i<=N; i++){  
            int n = *st.lower_bound(-arr[i]);
            ans += -n;
            if(n == 0){
                continue;
            }
            st.erase(n);
        }
        cout << ans << "\n";
    }
}