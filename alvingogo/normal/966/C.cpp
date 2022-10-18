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
    int n;
    cin >> n;
    vector<long long> b(n);
    vector<queue<long long> > z(64);
    for(int i=0;i<n;i++){
        cin >> b[i];
        int lk=__lg(b[i]);
        z[lk].push(b[i]);
    }
    vector<long long> p;
    for(int i=63;i>=0;i--){
        if(z[i].empty()){
            continue;
        }
        int nw=0;
        vector<int> tmp;
        auto h=z[i].front();
        z[i].pop();
        tmp.push_back(h);
        nw=h;
        for(int j=0;j<p.size();j++){
            tmp.push_back(p[j]);
            nw^=p[j];
            if(z[i].size()){
                auto h=z[i].front();
                if((nw^h)>nw){
                    nw^=h;
                    tmp.push_back(h);
                    z[i].pop();
                }
            }
                
        }
        p=tmp;
        if(z[i].size()){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for(auto h:p){
        cout << h << " ";
    }
    cout << "\n";
    return 0;
}