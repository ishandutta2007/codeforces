#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int pre[3][100005];
vector<pair<int, int>> ans;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        pre[arr[i]][i]++;
        pre[1][i] += pre[1][i-1];
        pre[2][i] += pre[2][i-1];
    }
    int lst = arr[N];
    for(int t = 1; t<=N; t++){
        int cnt1 = 0, cnt2 = 0;
        int crnt = 0;
        while(crnt < N){
            int l = crnt, r = N, idx = N+1;
            while(l <= r){
                int mid = l+r>>1;
                if(pre[1][mid]-pre[1][crnt] >= t || pre[2][mid] - pre[2][crnt] >= t){
                    r = mid - 1;
                    idx = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            if(pre[1][idx]-pre[1][crnt] == t){
                cnt1++;
            }
            else{
                cnt2++;
            }
            crnt = idx;
        }
        if(crnt == N){
            if(lst == 1 && cnt1 > cnt2){
                ans.push_back({cnt1, t});
            }
            else if(lst == 2 && cnt2 > cnt1){
                ans.push_back({cnt2, t});
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto n : ans){
        cout << n.first << " " << n.second << endl;
    }
}