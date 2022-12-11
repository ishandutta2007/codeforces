#include <bits/stdc++.h>

using namespace std;

int N;
pair<double, double> arr[1005];
unordered_map<double, long long> mp;
unordered_map<double, unordered_set<double>> ln;
unordered_set<int> st;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    long long cnt = 0;
    long long vert = 0;
    long long X = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<i; j++){
            if(arr[i].first-arr[j].first == 0){
                if(st.count(arr[i].first)){
                    continue;
                }
                cnt += vert;
                vert++;
                st.insert(arr[i].first);
            }
            else{
                double s = (arr[i].second-arr[j].second)/(arr[i].first-arr[j].first);
                double b = arr[i].second - s*arr[i].first;
                if(ln[s].count(b)){
                    continue;
                }
                cnt += mp[s];
                mp[{(arr[i].second-arr[j].second)/(arr[i].first-arr[j].first)}]++;
                ln[s].insert(b);
            }
            X++;
        }
    }
    /*
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<i; j++){
            if(i == j){
                continue;
            }
            if(arr[i].first-arr[j].first == 0){
                cnt += vert;
                cout << i << " " << j << " " << vert << endl;
            }
            else{
                cnt += mp[{(arr[i].second-arr[j].second)/(arr[i].first-arr[j].first)}];
                cout << i << " " << j << " " << mp[{(arr[i].second-arr[j].second)/(arr[i].first-arr[j].first)}] << endl;
            }
        }
    }
    */
    cout << X*(X-1)/2-cnt << endl;
}