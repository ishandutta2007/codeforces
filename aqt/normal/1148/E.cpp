#include <bits/stdc++.h>

using namespace std;

int N;
pair<int,int> arr[300005];
int brr[300005];
vector<pair<pair<int, int>,int>> vec;
int diff[300005];
stack<pair<int, int>> stk;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long tot1 = 0, tot2 = 0;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first;
        tot1 += arr[i].first;
        arr[i].second = i;
    }
    for(int i = 1; i<=N; i++){
        cin >> brr[i];
        tot2 += brr[i];
    }
    if(tot1 != tot2){
        cout << "NO" << endl;
        return 0;
    }
    sort(arr+1, arr+1+N);
    sort(brr+1, brr+1+N);
    for(int i = 1; i<=N; i++){
        diff[i] = brr[i] - arr[i].first;
    }
    for(int i = 1; i<=N; i++){
        if(diff[i] < 0){
            while(stk.size() && diff[i]){
                int k = min(-diff[i], stk.top().first);
                vec.push_back({{stk.top().second, arr[i].second}, k});
                diff[i] += k;
                stk.top().first -= k;
                if(!stk.top().first){
                    stk.pop();
                }
            }
            if(diff[i] < 0 && stk.empty()){
                cout << "NO" << endl;
                return 0;
            }
        }
        else{
            stk.push({diff[i], arr[i].second});
        }
    }
    cout << "YES" << "\n";
    cout << vec.size() << "\n";
    for(auto p : vec){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}