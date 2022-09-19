#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)250000;

stack<pll> s;
ll a[110];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, k;
    cin >> n >> k >> a[0];
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll m = 0;
    ll d, cnt;
    for(int i = 0; i < n + 1; i++){
        d = 0;
        while(s.size() > 0) s.pop();
        for(int j = 0;j < n + 2; j++){
            if(s.size() == 0){
                s.push(mp(a[j], 1ll));
            } else {
                if(s.top().F == a[j]){
                    cnt = s.top().S + 1;
                    s.pop();
                    s.push(mp(a[j], cnt));
                } else {
                    if(s.top().S >= 3){
                        d += s.top().S;
                        s.pop();
                        if(s.size() == 0){
                            s.push(mp(a[j], 1ll));
                            continue;
                        }
                        if(s.top().F == a[j]){
                            cnt = s.top().S + 1;
                            s.pop();
                            s.push(mp(a[j], cnt));
                        } else {
                            s.push(mp(a[j], 1ll));
                        }
                        //s.push(mp(a[j], 1ll));
                    } else {
                        s.push(mp(a[j], 1ll));
                    }
                }
            }
        }
        //cout << d << " " << i << endl;
        swap(a[i], a[i+1]);
        m = max(m, d - 1);
    }

    cout << m;
    return 0;
}



/*
           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/