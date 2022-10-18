#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<vector<int> > c(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
            v[i]--;
            c[v[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            int cnt=1;
            if(c[i].size()==0){
                cout << 0 << " ";
                continue;
            }
            for(int j=0;j<c[i].size()-1;j++){
                cnt+=((c[i][j+1]-c[i][j])%2);
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}