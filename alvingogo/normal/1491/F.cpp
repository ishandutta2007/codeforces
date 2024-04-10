#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mk=0;
        for(int i=1;i<n;i++){
            cout << "? " << 1 << " " << i << "\n";
            cout << i+1 << "\n";
            for(int j=1;j<=i;j++){
                cout << j << " ";
            }
            cout << endl;
            int f;
            cin >> f;
            if(f!=0){
                mk=i+1;
                break;
            }
        }
        vector<int> ans;
        for(int j=mk+1;j<=n;j++){
            cout << "? 1 1\n";
            cout << mk << "\n" << j << endl;
            int a;
            cin >> a;
            if(!a){
                ans.push_back(j);
            }
        }
        int l=1,r=mk-1;
        while(r>l){
            int m=(l+r)/2;
            cout << "? 1" << " " << m-l+1 << "\n";
            cout << mk << "\n";
            for(int i=l;i<=m;i++){
                cout << i << " ";
            }
            cout << endl;
            int a;
            cin >> a;
            if(a){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        for(int i=1;i<mk;i++){
            if(i!=l){
                ans.push_back(i);
            }
        }
        cout << "! ";
        cout << ans.size() << " ";
        for(auto h:ans){
            cout << h << " ";
        }
        cout << endl;
    }
    return 0;
}