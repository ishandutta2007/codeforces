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
    const int x=1e9;
    int tt;
    cin >> tt;
    while(tt--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int> > ss,v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].sc >> v[i].fs;
            ss.push_back({v[i].sc-v[i].fs+1,1});
            ss.push_back({v[i].sc+1,-2});
            ss.push_back({v[i].sc+v[i].fs+1,1});
        }
        sort(ss.begin(),ss.end());
        int s=0,a=0;
        int l=-1,r=-1,ml=-1e18,mr=-1e18;
        map<int,int> ma;
        int ls=0,la=0;
        auto chk=[&](int p,int a){
            if(a<=m){
                return;
            }
            if(a-p>=ml){
                ml=a-p;
                l=p;
            }  
            if(a+p>mr){
                r=p;
                mr=a+p;
            }
        };
        for(int i=0;i<ss.size();i++){
            s+=ss[i].sc;
            if(i==ss.size()-1 || ss[i].fs!=ss[i+1].fs){
                a=a+ls*(ss[i].fs-la-1);
                ls=s;
                la=ss[i].fs;
                ma[ss[i].fs-1]=a;
                chk(ss[i].fs-1,a);
                a+=s;
                ma[ss[i].fs]=a;
                chk(ss[i].fs,a);
            }
        }
        for(int i=0;i<n;i++){
            if(ma[l]-max(0ll,v[i].fs-abs(v[i].sc-l))>m || ma[r]-max(0ll,v[i].fs-abs(v[i].sc-r))>m){
                cout << 0;
            }
            else{
                cout << 1;
            }
        }
        cout << "\n";
    }
    
    return 0;
}