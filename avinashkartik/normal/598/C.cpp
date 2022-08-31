#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

pair <ld,int> p; 
vector <pair<ld,int>> v;
ll a[100005],b[100005],l[500005]={};

int n,x,y;
ld pi = acos(-1);

int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x>>y;
        ld angle = atan2(y,x);
        if(angle < 0)
            angle += 2*pi;
        p = make_pair(angle,i+1);
        v.push_back(p);
    }
 
    sort(v.begin(), v.end());
    ld minx = 1e10;
    ll mina,minb;

    for(int i = 0; i < n; i++){
        ld angle = v[(i+1)%n].first - v[i].first;
        //cout<<angle<<endl;
        if(angle < 0)
            angle += 2*pi;
        if(angle < minx){
            minx = angle;
            minb = v[(i+1)%n].second;
            mina = v[i].second;
        }
    }
 
    cout<<mina<<" "<<minb;
    
}