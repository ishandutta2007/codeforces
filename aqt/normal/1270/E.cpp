#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[1005];
int ans[1005];
vector<int> v;
int cnt[2][2];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    int x = arr[1].first+2e6, y = arr[1].second+2e6;
    while(1){
        cnt[0][0] = cnt[1][0] = cnt[0][1] = cnt[1][1] = 0;
        for(int i = 1; i<=N; i++){
            arr[i].first += 2e6, arr[i].second += 2e6;
            cnt[arr[i].first%2][arr[i].second%2]++;
        }
        int cnt0 = !!cnt[0][0] + !!cnt[1][0] + !!cnt[0][1] + !!cnt[1][1];
        //cout << cnt0 << endl;
        //cout << cnt[0][0] << " " << cnt[1][0] << " " << cnt[0][1] << " " << cnt[1][1] << endl;
        if(cnt0 > 1){
            if((cnt[0][0] || cnt[1][1]) && (cnt[1][0] || cnt[0][1])){
                for(int i = 1; i<=N; i++){
                    if(arr[i].first%2 == arr[i].second%2){
                        v.push_back(i);
                    }
                }
            }
            else if(cnt[0][0]){
                for(int i = 1;i <=N; i++){
                    if(arr[i].first%2 == 0 && arr[i].second%2 == 0){
                        v.push_back(i);
                    }
                }
            }
            else if(cnt[0][1]){
                for(int i = 1; i<=N; i++){
                    if(arr[i].first%2 == 0 && arr[i].second%2 == 1){
                        v.push_back(i);
                    }
                }
            }
            else{
                assert(0);
            }
            cout << v.size() << "\n";
            for(int n : v){
                cout << n << " ";
            }
            exit(0);
        }
        else{
            for(int i = 1; i<=N; i++){
                arr[i].first -= x;
                arr[i].second -= y;
                arr[i].first /= 2, arr[i].second /= 2;
            }
        }
    }
}