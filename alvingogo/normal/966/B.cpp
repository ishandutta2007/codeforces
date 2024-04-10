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
    int a,b,n;
    cin >> n >> a >> b;
    vector<pair<int,int> > c(n);
    for(int i=0;i<n;i++){
        cin >> c[i].fs;
        c[i].sc=i;
    }
    sort(c.begin(),c.end());
    vector<pair<long long,int> > v(n);
    for(int i=n-1;i>=0;i--){
        v[i].fs=1ll*c[i].fs*(n-i);
        v[i].sc=i;
        if(i!=n-1){
            v[i]=max(v[i],v[i+1]);
        }
    }
    for(int z=0;z<2;z++){
        for(int j=1;j<n;j++){
            int u=(a+j-1)/j;
            int h=lower_bound(c.begin(),c.end(),pair<int,int>{u,-1})-c.begin();
            if(h+j>=n){
                continue;
            }
            if(v[h+j].fs>=b){
                if(z==0){
                    cout << "Yes\n";
                    cout << j << " " << n-v[h+j].sc << "\n";
                    for(int i=h;i<h+j;i++){
                        cout << c[i].sc+1 << " ";
                    }   
                    cout << "\n";
                    for(int i=v[h+j].sc;i<n;i++){
                        cout << c[i].sc+1 << " ";
                    }
                    cout << "\n";
                }
                else{
                    cout << "Yes\n";
                    cout << n-v[h+j].sc << " " << j << "\n";
                    for(int i=v[h+j].sc;i<n;i++){
                        cout << c[i].sc+1 << " ";
                    }
                    cout << "\n";
                    for(int i=h;i<h+j;i++){
                        cout << c[i].sc+1 << " ";
                    }   
                    cout << "\n";
                }
                return 0;
            }
        }
        swap(a,b);
    }
    cout << "No\n";
    return 0;
}