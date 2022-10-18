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
        int h,g;
        cin >> h >> g;
        int n=(1<<h)-1,m=(1<<g)-1;
        vector<int> v(n);
        vector<pair<int,int> > a;
        for(int i=0;i<n;i++){
            cin >> v[i];
            a.push_back({v[i],i+1});
        }
        sort(a.begin(),a.end());
        auto b=a;
        vector<int> x(m+1);
        long long ans=0;
        vector<int> z(n);
        for(int i=0;i<n;i++){
            while(a[i].sc>1){
                a[i].sc/=2;
                if(a[i].sc<=m){
                    if(x[a[i].sc]==0){
                        if(a[i].sc*2>m || (x[2*a[i].sc]>0 && x[2*a[i].sc+1]>0)){
                            x[a[i].sc]=a[i].fs;
                            ans+=a[i].fs;
                            z[b[i].sc-1]=1;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
        for(int i=n-1;i>=0;i--){
            if(z[i]==0){
                cout << i+1 << " ";
            }            
        }
        cout << "\n";
    }
    return 0;
}