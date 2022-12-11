#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> st[2];
int arr[200005];
set<int> dis;
vector<int> rem;
int cnt[2];

int main(){
    cin >> N >> M;
    M = min(M, N);
    int ans = 0;
    for(int i = 1; i<=M; i++){
        st[i%2].insert(i);
    }
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        if(st[arr[i]%2].count(arr[i])){
            st[arr[i]%2].erase(arr[i]);
        }
        if(dis.count(arr[i])){
            rem.push_back(i);
            ans++;
            continue;
        }
        dis.insert(arr[i]);
        cnt[arr[i]&1]++;
    }
    for(int n : rem){
        if(cnt[0] > cnt[1]){
            if(st[1].empty()){
                cout << -1 << endl;
                return 0;
            }
            arr[n] = *st[1].begin();
            st[1].erase(*st[1].begin());
            cnt[1]++;
        }
        else{
            if(st[0].empty()){
                cout << -1 << endl;
                return 0;
            }
            arr[n] = *st[0].begin();
            st[0].erase(*st[0].begin());
            cnt[0]++;
        }
    }
    for(int i= 1; i<=N && cnt[0] != cnt[1]; i++){
        if(cnt[0] > cnt[1] && arr[i]%2 == 0){
            if(st[1].empty()){
                cout << -1 << endl;
                return 0;
            }
            arr[i] = *st[1].begin();
            st[1].erase(st[1].begin());
            cnt[0]--, cnt[1]++;
            ans++;
        }
        else if(cnt[0] < cnt[1] && arr[i]%2 == 1){
            if(st[0].empty()){
                cout << -1 << endl;
                return 0;
            }
            arr[i] = *st[0].begin();
            st[0].erase(st[0].begin());
            cnt[1]--, cnt[0]++;
            ans++;
        }
    }
    cout << ans << "\n";
    for(int i = 1; i<=N; i++){
        cout << arr[i] << " ";
    }
}