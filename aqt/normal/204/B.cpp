#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;
int a[100005], b[100005];
int N;

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> a[i] >> b[i];
        mp[a[i]]++;
        if(a[i] != b[i]){
            mp[b[i]]++;
        }
    }
    int ans = INT_MAX;
    for(pair<int, int> p : mp){
        if(p.second >= (N+1)/2){
            int cnt1 = 0, cnt2 = 0;
            for(int i = 1; i<=N; i++){
                if(a[i] == p.first){
                    cnt1++;
                }
            }
            if(cnt1 >= (N+1)/2){
                ans = 0;
            }
            else{
                for(int i = 1; i<=N && cnt1 < (N+1)/2; i++){
                    if(a[i] != p.first && b[i] == p.first){
                        cnt1++;
                        cnt2++;
                    }
                }
                ans = min(ans, cnt2);
            }
        }
    }
    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}