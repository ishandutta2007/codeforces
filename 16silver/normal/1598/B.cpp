#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<array<int,5>> v(n);
    for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin >> v[i][j];
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            bool flag = true;
            int tmp1=0, tmp2=0;
            for(int k=0;k<n;k++){
                if(v[k][i]==0 && v[k][j]==0) flag = false;
                if(v[k][i]==1) tmp1++;
                if(v[k][j]==1) tmp2++;
            }
            if(flag && tmp1>=n/2 && tmp2>=n/2){
                cout << "YES\n";
                return;
            }
        }
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