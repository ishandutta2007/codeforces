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
        int n,m;
        cin >> n >> m;
        vector<vector<int> > v(n,vector<int>(m));
        vector<vector<int> > h=v;
        set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
                h[i][j]=v[i][j];
            }
            sort(h[i].begin(),h[i].end());
            for(int j=0;j<m;j++){
                if(v[i][j]!=h[i][j]){
                    s.insert(j);
                }
            }
        }
        if(s.size()==0){
            cout << 1 << " " << 1 << "\n";
        }
        else if(s.size()==2){
            vector<int> l;
            for(auto a:s){
                l.push_back(a);
            }
            int flag=0;
            for(int i=0;i<n;i++){
                swap(v[i][l[0]],v[i][l[1]]);
                if(v[i][l[0]]!=h[i][l[0]] || v[i][l[1]]!=h[i][l[1]]){
                    flag=1;
                }
            }
            if(flag){
                cout << -1 << "\n";
                continue;
            }
            for(auto a:s){
                cout << a+1 << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
	return 0;
}