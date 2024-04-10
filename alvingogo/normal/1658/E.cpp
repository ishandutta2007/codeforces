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
    int n,k;
    cin >> n >> k;
    vector<vector<int> > f(n,vector<int>(n));
    vector<pair<int,pair<int,int> > > v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            v.push_back({-a,{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int l,r,u,d;
    l=r=v[0].sc.fs+v[0].sc.sc;
    u=d=v[0].sc.fs-v[0].sc.sc;
    for(auto h:v){
        auto a=h.sc.fs+h.sc.sc;
        auto b=h.sc.fs-h.sc.sc;
        if(abs(l-a)<=k && abs(r-a)<=k && abs(u-b)<=k && abs(d-b)<=k){
            f[h.sc.fs][h.sc.sc]=1;
            l=min(l,a);
            r=max(r,a);
            u=min(u,b);
            d=max(d,b);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << (f[i][j]?'M':'G');
        }
        cout << "\n";
    }
	return 0;
}