#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 1000005
#define INF 101111111111111
using namespace std;
bool mark[N];
ll djk(ll start){
    queue<pll> pq;
    mark[start] = 1;
    pq.push({0, start});
    while(!pq.empty()){
        pll got = pq.front();
        pq.pop();
        ll cl = got.x;
        ll nm = got.y;
        if(nm == 0){
            return cl;
        }
        ll os = nm;
        while(os){
            if(!mark[nm-os%10]){
                pq.push({cl+1, nm-os%10});
                mark[nm-os%10] = 1;
            }
            os/=10;
        }
    }
    return -1;
}
main(){
    FAST;
    ll n;
    cin >> n;
    ll rs = djk(n);
    cout << rs;
}