#include<iostream>
#define x first
#define y second
#define ll long long
using namespace std;
int n, m, i, k, b, s, t, p, u;
ll sb, ss;
pair<ll, ll> c[300005], pct;
ll det(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
int main(){
    cin>> n >> m;
    u = 1;
    for(; m; m--){
        cin>> t;
        if(t == 1){
            cin>> k;
            sb = ss = 0;
            n += k;
            u = 1;
            c[1] = make_pair(0, 0);
            cout<<"1 0\n";
            continue;
        }
        if(t == 2){
            cin>> k;
            pct = make_pair(n, -sb - ss * n);
            n += k;
            if(c[u].x * ss + sb + c[u].y == 0){
                cout<< c[u].x + 1 <<" 0\n";
                continue;
            }
            while(u >= 2 && det(c[u - 1], c[u], pct) < 0){
                u--;
            }
            c[++u] = pct;
            cout<< pct.x + 1<<" 0\n";
            continue;
        }
        cin>> b >> s;
        sb += b;
        ss += s;
        while(u >= 2 && c[u].x * ss + sb + c[u].y >= c[u - 1].x * ss + sb + c[u - 1].y){
            u--;
        }
        cout<< c[u].x + 1 <<" "<< c[u].x * ss + sb + c[u].y <<"\n";
    }
}