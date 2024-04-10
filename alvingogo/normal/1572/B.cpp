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
        int z=0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            z^=v[i];
        }
        vector<int> ans;
        auto use=[&](vector<int> v,int z){
            for(int i=0;i<v.size()-1;i+=2){
                ans.push_back(i+z);
            }
            for(int i=v.size()-3;i>=0;i-=2){
                ans.push_back(i+z);
            }
        };
        auto print=[&]{
            cout << ans.size() << "\n";
            for(auto h:ans){
                cout << h+1 << " ";
            }
            cout << "\n";
        };
        if(z){
            cout << "NO\n";
            continue;
        }
        if(n%2){
            cout << "YES\n";
            use(v,0);
            print();
        }
        else{
            vector<int> a(n);
            for(int i=0;i<n;i++){
                a[i]=v[i];
            }
            for(int i=1;i<n;i++){
                a[i]^=a[i-1];
            }
            int flag=0;
            for(int i=0;i<n;i+=2){
                if(a[i]==0){
                    cout << "YES\n";
                    vector<int> c,d;
                    for(int j=0;j<=i;j++){
                        c.push_back(v[j]);
                    }
                    for(int j=i+1;j<n;j++){
                        d.push_back(v[j]);
                    }
                    use(c,0);
                    use(d,i+1);
                    flag=1;
                    print();
                    break;
                }
            }
            if(flag){
                continue;
            }
            cout << "NO\n";
        }
    }
    
    return 0;
}