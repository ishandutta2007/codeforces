#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll=long long;
const int N=200005,P=1000000007;
void work(){
    int n,r[3],c[3],x,y;
    cin>>n;
    for(int i=0;i<3;i++)
        cin>>r[i]>>c[i];
    cin>>x>>y;
    int cc,rr;
    rr=((r[0]+r[1]+r[2])-(r[0]^r[1]^r[2]))/2;
    cc=((c[0]+c[1]+c[2])-(c[0]^c[1]^c[2]))/2;
    if((rr==1||rr==n)&&(cc==1||cc==n)){
        if(x==rr||y==cc) puts("YES");
        else puts("NO");
    }
    else if(((x^rr)&1)&&((y^cc)&1)) puts("NO");
    else puts("YES");
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) work();
    return 0;
}