#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int w[60], P[60];
void Do(vector<int>VV){
    int pv=0;
    vector<vector<int>>U;
    for(auto &t : VV){
        vector<int>ZZ;
        for(int i=0;i<t;i++){
            pv++;
            ZZ.push_back(w[pv]);
        }
        U.push_back(ZZ);
    }
    reverse(U.begin(),U.end());
    pv=0;
    for(auto &t : U){
        for(auto &x : t){
            pv++;
            w[pv] = x;
        }
    }
}
void Solve(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    vector<vector<int>>Ans;
    while(1){
        for(i=1;i<=n;i++)P[w[i]]=i;
        vector<int>Z;
        int ck=0;
        for(i=1;i<n;i++){
            if(P[i] > P[i+1]){
                int pv = P[i+1];
                while(w[pv+1]==w[pv]+1)pv++;
                Z.push_back(P[i+1]-1);
                Z.push_back(pv-P[i+1]+1);
                Z.push_back(P[i]-pv);
                Z.push_back(n-P[i]);
                ck=1;
                break;
            }
        }
        if(!ck)break;
        vector<int>VV;
        for(auto &t : Z){
            if(t)VV.push_back(t);
        }
        Do(VV);
        Ans.push_back(VV);
//        for(i=1;i<=n;i++)printf("%d ",w[i]);
//        puts("");
    }
    printf("%d\n",Ans.size());
    for(auto &t : Ans){
        printf("%d ",t.size());
        for(auto &x : t)printf("%d ",x);
        puts("");
    }
}
int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}