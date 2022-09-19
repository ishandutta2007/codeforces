#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)1e6+10;

ll r[5000];
ll rt[5000];
ll c[5000];
ll ct[5000];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n, m, k;
    cin >> n  >> m >> k;
    ll t,x,co;
    for(int i =0;i<k;i++){
        cin >> t >> x >> co;
        if(t==1){
            r[x-1] = co;
            rt[x-1] = i+1;
        }
        if(t==2){
            c[x-1] = co;
            ct[x-1] = i+1;
        }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(rt[i] > ct[j]){
                cout << r[i] << " ";
            }else cout << c[j] << " ";
        }
        cout << endl;
    }

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