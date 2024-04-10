#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int ans;
bool check(vector<int> v){
    int n=v.size();
    vector<vector<int> > e(30);
    for(int i=0;i<n;i++){
        for(int j=0;j<30;j++){
            if((v[i]>>j)&1){
                e[j].push_back(i);
            }
        }
    }
    vector<int> vis(30),v2(n);
    v2[0]=1;
    queue<int> q;
    q.push(0);
    while(q.size()){
        int h=q.front();
        q.pop();
        for(int i=0;i<30;i++){
            if((v[h]>>i)&1){
                if(!vis[i]){
                    vis[i]=1;
                    for(auto p:e[i]){
                        if(!v2[p]){
                            q.push(p);
                            v2[p]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!v2[i]){
            return 0;
        }
    }
    cout << ans << "\n";
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
    return 1;
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        ans=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(!v[i]){
                v[i]=1;
                ans++;
            }
        }
        if(check(v)){
            continue;
        }
        ans++;
        int flag=0;
        for(int i=0;i<n;i++){
            v[i]--;
            if(check(v)){
                flag=1;
                break;
            }
            v[i]++;
        }
        if(flag){
            continue;
        }
        for(int i=0;i<n;i++){
            v[i]++;
            if(check(v)){
                flag=1;
                break;
            }
            v[i]--;
        }
        if(flag){
            continue;
        }
        ans++;
        int nw=0,mxz=0;
        for(int i=0;i<n;i++){
            int p=(v[i]&-v[i]);
            if(p>mxz){
                mxz=p;
                nw=i;
            }
        }
        v[nw]--;
        nw=0;
        mxz=0;
        for(int i=0;i<n;i++){
            int p=(v[i]&-v[i]);
            if(p>mxz){
                mxz=p;
                nw=i;
            }
        }
        v[nw]++;
        cout << ans << "\n";
        for(int i=0;i<n;i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}