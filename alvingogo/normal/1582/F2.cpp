#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> ab(8192);
    vector<vector<int> > go(5005);
    vector<int> r(8192);
    for(int i=0;i<5005;i++){
        go[i].push_back(0);
    }
    for(int i=0;i<8192;i++){
        r[i]=5004;
    }
    r[0]=0;
    ab[0]=1;
    for(auto h:v){
        if(h==0){
            continue;
        }
        for(auto z:go[h]){
            int a=z^h;
            ab[a]=1;
            for(int& i=r[a];i>h;i--){
                go[i].push_back(a);
            }
        }
        go[h].clear();
    }
    int cnt=0;
    for(int i=0;i<8192;i++){
        if(ab[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i=0;i<8192;i++){
        if(ab[i]){
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}