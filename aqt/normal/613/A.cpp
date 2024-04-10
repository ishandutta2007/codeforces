#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    long long px, py;
    cin >> px >> py;
    long double mn = 1e13, mx = 0;
    vector<pair<long long, long long>> v;
    for(int i = 0; i<N; i++){
        long long x, y;
        cin >> x >> y;
        x -= px, y -= py;
        v.push_back({x, y});
        mn = min(mn, (long double) sqrt(x*x+y*y));
        mx = max(mx, (long double) sqrt(x*x+y*y));
    }
    for(int i=0 ; i<N; i++){ //stackoverflow blessed
        auto p = v[i], q = v[(i+1)%N];
        long double r = (-p.first)*(q.first-p.first)-p.second*(q.second-p.second);
        long double d = sqrt((p.first-q.first)*(p.first-q.first) + (p.second-q.second)*(p.second-q.second));
        r /= d;
        long double h = sqrt(p.first*p.first+p.second*p.second);
        r /= h;
        long double s = (-q.first)*(p.first-q.first)-q.second*(p.second-q.second);
        s /= d;
        long double g = sqrt(q.first*q.first+q.second*q.second);
        s /= g;
        if(r > 0 && r < 1 && s > 0 && s < 1){
            mn = min(mn, sqrt(1-r*r)*h);
        }
    }
    cout.precision(20);
    cout << (mx*mx-mn*mn)*3.14159265358979323846 << endl;
}