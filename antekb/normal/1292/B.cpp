#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int N=1000;
long long dist[N];
int main(){
    long long x0, y0, ax, ay, bx, by, xs, ys, t;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    vector<long long> X={x0}, Y={y0};

    for(int i=1; ; i++){
        if(X[i-1]>(INF-bx)/ax)  break;
        X.push_back(X[i-1]*ax+bx);
        dist[i-1]+=abs(X[i-1]-X[i]);
        //cout<<X[i]<<"\n";
    }
    for(int i=1; ; i++){
        if(Y[i-1]>(INF-by)/ay)  break;
        Y.push_back(Y[i-1]*ay+by);
        dist[i-1]+=Y[i]-Y[i-1];
        //cout<<Y[i]<<"\n";
    }
    int cnt=0;
    for(int i=0; i<X.size() and i<Y.size(); i++){
        long long dl=0;
        for(int j=i; j<X.size() and j<Y.size(); j++){
            if(min(abs(xs-X[i])+abs(ys-Y[i]), abs(xs-X[j])+abs(ys-Y[j]))+dl<=t){
                cnt=max(cnt, j-i+1);
            }
            dl+=dist[j];
        }
    }
    cout<<cnt;
}