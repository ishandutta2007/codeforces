
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
ll const MAXN = (ll)2e5 + 10;

ll val[MAXN];
ll nex[MAXN];
ll pre[MAXN];

ll fi[MAXN];
ll la[MAXN];

ll a[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < MAXN; i++) nex[i] = i + 1;
    for(int i = 0; i < MAXN; i++) pre[i] = i - 1;
    //pre[0] = 0;
    fill(fi,fi+MAXN,-1);
    ll n, q, v;
    cin >> n >> q;
    ll f0 = -1;
    for(int i = 0; i < n; i++){
        cin >> v;
        a[i] = v;
        if(v == 0) {
            if(f0 == -1)f0 = i;
            continue;
        }
        if(fi[v] == -1) fi[v] = i;
        la[v] = i;
    }
    ll po;
    for(int i =  q; i > 0; i--){
        if(fi[i] == -1){
            continue;
        } else {
            if((val[fi[i]] != 0) or(val[la[i]]!= 0)){
                cout << "NO" ;
                return 0;
            }
            if(pre[fi[i]] != -1){
                pre[nex[la[i]]] = pre[fi[i]];
                nex[pre[fi[i]]] = nex[la[i]];
            }else{
                pre[nex[la[i]]] = -1;
            }
            po = fi[i];
            //cerr << 2 << la[i] << " " << i << " " << fi[i];
            while(po != la[i]){
                //cerr << po;
                val[po] = i;
                po = nex[po];
            }
            //cerr << 2 << endl;
            val[la[i]] = i;
        }
    }
    for(int i =0;i < n ;i++){
        if(val[i] != 0 and a[i]!= 0 and val[i]!=a[i]){
            cout << "NO";
            return 0;
        }
        if(val[i] == 0)val[i] = 1;

    }
    if(fi[q] == -1){
        if(f0 == -1){
            cout << "NO";
            return 0;
        }else{
            val[f0] = q;
        }
    }
    cout << "YES" << endl;
    for(int i = 0;i<n;i++)cout << val[i] << " ";
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