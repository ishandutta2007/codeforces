#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[500005];
stack<int> stk;
vector<pair<int, int>> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        bool pos = 1;
        while(stk.size()){
            stk.pop();
        }
        v.clear();
        for(int i = 1; i<=N; i++){
            while(stk.size() && stk.top() == i){
                stk.pop();
            }
            cin >> arr[i];
            if(arr[i] == -1){
                if(stk.empty()){
                    arr[i] = N+1;
                }
                else{
                    arr[i] = stk.top();
                }
            }
            v.push_back({-arr[i], i});
            if(stk.size() && stk.top() < arr[i]){
                pos = 0;
            }
            stk.push(arr[i]);
        }
        if(pos){
            sort(v.begin(), v.end());
            int cnt = N;
            for(auto p : v){
                arr[p.second] = cnt--;
            }
            for(int i= 1; i<=N; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}