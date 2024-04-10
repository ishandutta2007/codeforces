#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int> > v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        vector<int> sx(n);
        vector<pair<int,int> > p;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sx[i]+=j*v[i][j];
            }
            p.push_back({sx[i],i});
        }
        sort(p.begin(),p.end(),greater<pair<int,int> >());
        cout << p[0].sc+1 << " " << p[0].fs-p[1].fs << "\n";
    }
    return 0;
}