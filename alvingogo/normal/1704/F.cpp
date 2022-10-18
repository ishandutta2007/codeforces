#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

signed main(){
    AquA;
    vector<int> gr(800);
    gr[0]=gr[1]=0;
    gr[2]=1;
    for(int i=3;i<800;i++){
        vector<int> g;
        for(int j=0;j<=i-2;j++){
            g.push_back(gr[j]^gr[i-2-j]);
        }
        vector<int> vis(2000);
        for(auto h:g){
            vis[h]=1;
        }
        for(int j=0;j<2000;j++){
            if(!vis[j]){
                gr[i]=j;
                break;
            }
        }
    }
    long long t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                a++;
            }
            else{
                b++;
            }
        }
        if(a!=b){
            if(a>b){
                cout << "Alice" << "\n";
            }
            else{
                cout << "Bob" << "\n";
            }
        }
        else{
            int cnt=1;
            int nw=0;
            for(int i=1;i<=n;i++){
                if(i==n || s[i]==s[i-1]){
                    if(cnt<800){
                        nw^=gr[cnt];
                    }
                    else{
                        nw^=gr[cnt%34+(34*15)];
                    }
                    cnt=1;
                }
                else{
                    cnt++;
                }
            }
            if(nw==0){
                cout << "Bob\n";
            }
            else{
                cout << "Alice\n";
            }
        }
    }
    return 0;
}