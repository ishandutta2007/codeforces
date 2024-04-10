#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int u;
bool cmp(int a,int b){
    return ((a>>u)&1)<((b>>u)&1);
}
bool cmp2(int a,int b){
    return ((a>>u)&1)>((b>>u)&1);
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(auto &h:a){
            cin >> h;
        }
        for(auto &h:b){
            cin >> h;
        }
        vector<int> v;
        v.push_back(0);
        v.push_back(n);
        int c=0;
        for(int i=30;i>=0;i--){
            int flag=0;
            vector<int> tmp;
            u=i;
            for(int j=0;j<v.size()-1;j++){
                sort(a.begin()+v[j],a.begin()+v[j+1],cmp);
                sort(b.begin()+v[j],b.begin()+v[j+1],cmp2);
                for(int k=v[j];k<v[j+1];k++){
                    if(!(((a[k]^b[k])>>i)&1)){
                        flag=1;
                        break;
                    }
                    if(k+1<v[j+1] && (((b[k]>>i)&1) && (!((b[k+1]>>i)&1)))){
                        tmp.push_back(k+1);
                    }
                }
            }
            if(!flag){
                c|=(1<<i);
                for(auto h:tmp){
                    v.push_back(h);
                }
                sort(v.begin(),v.end());
            }
        }
        cout << c << "\n";
    }
    return 0;
}