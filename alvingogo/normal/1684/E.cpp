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
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(),v.end());
        auto y=v;
        y.erase(unique(y.begin(),y.end()),y.end());
        int i=0;
        while(i<y.size() && y[i]-i<=k){
            i++;
        }
        int mex=k+i;
        map<int,int> m,m2;
        for(int j=0;j<n;j++){
            if(v[j]<mex){
                continue;
            }
            m[v[j]]++;
        }
        for(auto h:m){
            m2[h.sc]++;
        }
        int dif=m.size();
        for(auto a:m2){
            if(a.fs*a.sc<=k){
                k-=a.fs*a.sc;
                dif-=a.sc;
            }
            else{
                int u=k/a.fs;
                dif-=u;
                break;
            }
        }
        cout << dif << "\n";
    }
	return 0;
}