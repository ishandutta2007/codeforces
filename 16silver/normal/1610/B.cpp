#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int idx1=0, idx2=n-1, tt=-1;
    while(idx2-idx1>0){
        if(v[idx1]==v[idx2]){
            idx1++;
            idx2--;
        }
        else{
            if(tt==-1){
                tt=v[idx2];
                idx2--;
            }
            else if(tt==v[idx2]){
                idx2--;
            }
            else if(tt==v[idx1]){
                idx1++;
            }
            else{
                break;
            }
        }
    }
    if(idx2-idx1<=0){
        cout << "YES\n";
        return;
    }
    idx1=0; idx2=n-1; tt=-1;
    while(idx2-idx1>0){
        if(v[idx1]==v[idx2]){
            idx1++;
            idx2--;
        }
        else{
            if(tt==-1){
                tt=v[idx1];
                idx1++;
            }
            else if(tt==v[idx2]){
                idx2--;
            }
            else if(tt==v[idx1]){
                idx1++;
            }
            else{
                break;
            }
        }
    }
    if(idx2-idx1<=0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}