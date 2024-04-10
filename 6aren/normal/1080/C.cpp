#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long ntest,x1,x2,x3,x4,yy1,y2,y3,y4,n,m;
typedef pair<long long,long long> ii;
ii cross(ll a1,ll b1,ll a2,ll b2,ll a3,ll b3,ll a4,ll b4){
    ii low=make_pair(max(a1,a3),max(b1,b3));
    ii up=make_pair(min(a2,a4),min(b2,b4));
    if ((low.first > up.first) || (low.second > up.second)) return make_pair(0,0);
    if ((up.first-low.first+1)*(up.second-low.second+1)%2==0) return make_pair((up.first-low.first+1)*(up.second-low.second+1)/2,(up.first-low.first+1)*(up.second-low.second+1)/2);
    if ((low.first+low.second)%2) return make_pair((up.first-low.first+1)*(up.second-low.second+1)/2,(up.first-low.first+1)*(up.second-low.second+1)/2+1);
    return make_pair((up.first-low.first+1)*(up.second-low.second+1)/2+1,(up.first-low.first+1)*(up.second-low.second+1)/2);
}
ii solve(ll a1,ll b1,ll a2,ll b2){
    if ((a2-a1+1)*(b2-b1+1)%2==0) return make_pair((a2-a1+1)*(b2-b1+1)/2,(a2-a1+1)*(b2-b1+1)/2);
    if ((a1+b1)%2) return make_pair((a2-a1+1)*(b2-b1+1)/2,(a2-a1+1)*(b2-b1+1)/2+1);
    return make_pair((a2-a1+1)*(b2-b1+1)/2+1,(a2-a1+1)*(b2-b1+1)/2);
}
int main(){
    cin >> ntest;
    for (int i=1;i<=ntest;i++){
        cin >> n >> m;
        cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        long long white,black;
        if (n*m%2==0) {
            white=n*m/2;
            black=n*m/2;
        } else {
            white=n*m/2+1;
            black=n*m/2;
        }
        ii u;
        u=solve(x1,yy1,x2,y2);
        white+=u.second;
        black-=u.second;
        u=solve(x3,y3,x4,y4);
        white-=u.first;
        black+=u.first;
        u=cross(x1,yy1,x2,y2,x3,y3,x4,y4);
        white-=u.second;
        black+=u.second;
        cout << white << " " << black << endl;
    }
}