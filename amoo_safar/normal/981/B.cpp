#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
bool is_p(string a){
    for(int i = 0;i<a.size();i++){
        if(a[i] != a[a.size()-i-1])return false;
    }
    return true;
}
int main(){
    ll n,m,x,y;
    map<ll,ll> a;
    cin >> n;
    ll out = 0;
    for(int i = 0;i<n;i++){
        cin >> x >> y;
        a[x] = y;
        out += y;
    }
    cin >> m;
    ll u;
    for(int i =0;i<m;i++){
        cin >> x >> y;
        u = a[x];
        if(y > u) out += (y-u);
        //cout << u<< " " <<out << endl;
    }
    cout << out;
    return 0;
}