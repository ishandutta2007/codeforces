//password1488
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
map<ll, pair<ll, pair<ll, ll>>> an;
ll bp(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return a*bp(a*a, b>>1);
    else return bp(a*a, b>>1);
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll a, i = 0;i<n;i++){
        cin >> a;
        ll oa = a;
        for(ll j = 2;j*j<=a;j++){
            ll c=0;
            while(oa%j==0) c++, oa/=j;
            if(c>0){
                if(!an.count(j)){
                    an[j] = {1, {c, 0}};
                }else{
                    if(an[j].x==1){
                        ll u = an[j].y.x;
                        an[j] = {2, {min(u, c), max(u, c)}};
                    }else{
                        an[j].x++;
                        if(c<an[j].y.x){
                            an[j].y.y = an[j].y.x;
                            an[j].y.x = c;
                        }else if(c<an[j].y.y){
                            an[j].y.y = c;
                        }
                    }
                }
            }
        }
        if(oa!=1){
            ll c = 1;
            ll j = oa;
            if(!an.count(j)){
                an[j] = {1, {c, 0}};
            }else{
                if(an[j].x==1){
                    ll u = an[j].y.x;
                    an[j] = {2, {min(u, c), max(u, c)}};
                }else{
                    an[j].x++;
                    if(c<an[j].y.x){
                        an[j].y.y = an[j].y.x;
                        an[j].y.x = c;
                    }else if(c<an[j].y.y){
                        an[j].y.y = c;
                    }
                }
            }
        }
    }
    ll out = 1;
    for(auto i : an){
        if(i.y.x==1 && n!=2) continue;
        if(i.y.x==1 && n==2){
            out *= bp(i.x, i.y.y.x);
            continue;
        }
        if(n-i.y.x==2) continue;
        if(n-i.y.x==1) out*=bp(i.x, i.y.y.x);
        if(n-i.y.x==0) out*=bp(i.x, i.y.y.y);
    }
    cout << out << '\n';
}