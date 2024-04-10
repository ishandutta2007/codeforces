#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
long long res;
void Do(vector<int>&A,vector<int>&B,vector<int>&C){
    for(auto &t : A){
        int p1 = lower_bound(B.begin(),B.end(),t+1) - B.begin();
        int p2 = lower_bound(C.begin(),C.end(),t) - C.begin();
        p1--;
        if(p1<0||p2>=C.size())continue;
        long long x = t-B[p1], y = C[p2]-t;
        res=min(res,x*x+y*y+(x+y)*(x+y));
    }
}
void Solve(){
    vector<int>A,B,C;
    int i, nA,nB,nC;
    res=9e18;
    A.clear(),B.clear(),C.clear();
    scanf("%d%d%d",&nA,&nB,&nC);
    for(i=0;i<nA;i++){
        int x;
        scanf("%d",&x);
        A.push_back(x);
    }
    for(i=0;i<nB;i++){
        int x;
        scanf("%d",&x);
        B.push_back(x);
    }
    for(i=0;i<nC;i++){
        int x;
        scanf("%d",&x);
        C.push_back(x);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    Do(A,B,C);
    Do(A,C,B);
    Do(B,A,C);
    Do(B,C,A);
    Do(C,A,B);
    Do(C,B,A);
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}