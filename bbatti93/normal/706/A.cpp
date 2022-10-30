#include <bits/stdc++.h>
using namespace std;

double x,y,n;

vector<double> xt;
vector<double> yt;
vector<double> vt;

long double mt2 = 1000000.0;

int main(){
    cin>>x>>y>>n;
    xt.resize(n);
    yt.resize(n);
    vt.resize(n);
    for (int i=0; i<n; i++){
        cin>>xt[i]>>yt[i]>>vt[i];
        mt2=min(mt2,(long double)(((x-xt[i])*(x-xt[i])+(y-yt[i])*(y-yt[i]))/(vt[i]*vt[i])));
    }
    cout<<setprecision(9)<<sqrt(mt2)<<endl;
}