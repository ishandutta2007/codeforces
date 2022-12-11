#include <bits/stdc++.h>

using namespace std;

vector<int> arr[200005];
int N, M, K;
unordered_map<int, int> mp;
int key[200005];
int win[400005], chk[400005];
vector<int> ans;

int main(){
    cin >> N >> M >> K;
    int cnt = 0;
    for(int i = 0; i<N; i++){
        int n;
        cin >> n;
        if(!mp.count(n)){
            mp.insert({n, ++cnt});
        }
        arr[i%K].push_back(n);
    }
    int d = 0;
    for(int i = 0; i<M; i++){
        int n;
        cin >> n;
        if(!mp.count(n)){
            mp.insert({n, ++cnt});
        }
        chk[mp[n]]++;
        if(chk[mp[n]] == 1){
            d++;
        }
    }
    for(int m = 0; m<K; m++){
        if(arr[m].size() < M){
            break;
        }
        int l = 0, r = 0, cnt = d;
        while(r < M-1){
            win[mp[arr[m][r]]]++;
            int dif = win[mp[arr[m][r]]] - chk[mp[arr[m][r]]];
            if(dif == 0){
                cnt--;
            }
            else if(dif == 1){
                cnt++;
            }
            r++;
        }
        while(r < arr[m].size()){
            win[mp[arr[m][r]]]++;
            int dif = win[mp[arr[m][r]]] - chk[mp[arr[m][r]]];
            if(dif == 0){
                cnt--;
            }
            else if(dif == 1){
                cnt++;
            }
            if(!cnt){
                ans.push_back(m+l*K);
            }
            win[mp[arr[m][l]]]--;
            dif = win[mp[arr[m][l]]] - chk[mp[arr[m][l]]];
            if(dif == 0){
                cnt--;
            }
            else if(dif == -1){
                cnt++;
            }
            l++;
            r++;
        }
        while(l < arr[m].size()){
            win[mp[arr[m][l]]] = 0;
            l++;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int n : ans){
        printf("%d ", n+1);
    }
}