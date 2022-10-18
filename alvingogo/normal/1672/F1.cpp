#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
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
        vector<vector<int> > cnt(n+1);
        set<int> ok;
        for(int i=0;i<n;i++){
            cin >> v[i];
            ok.insert(v[i]);
            cnt[v[i]].push_back(i);
        }
        vector<int> b(n);
        for(int i=1;i<=n;i++){
            if(ok.empty()){
                break;
            }
            vector<int> l;
            vector<pair<int,int> > ou;
            for(auto h:ok){
                if(cnt[h].size()<i){
                    l.push_back(h);
                }
                else{
                    ou.push_back({cnt[h][i-1],h});
                }
            }
            for(auto y:l){
                ok.erase(y);
            }
            if(ou.empty()){
                break;
            }
            ou.push_back(ou[0]);
            for(int j=1;j<ou.size();j++){
                b[ou[j-1].fs]=ou[j].sc;
            }
        }
        for(auto h:b){
            cout << h << " ";
        }
        cout << "\n";
    }
	return 0;
}