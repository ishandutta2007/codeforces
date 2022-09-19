#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = 400010;

ll c[100][100];
ll a[100];
ll b[100];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll s=0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        s = s ^ a[i];
    }
    for(int i =0;i<m;i++){
        cin >> b[i];
        s = s^b[i];
    }
    if(s != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll v = 1073741823;
    cout << "YES\n";
    for (int i =1;i<n;i++){
        for(int j = 1;j<m;j++)c[i][j] = v;
    }
    ll nv,mv;
    if(n%2 == 0) nv = v;
    else nv = 0;
    if(m%2==0) mv = v;
    else mv = 0;
    ll x = a[0];
    for(int j = 1;j<m;j++){
        c[0][j] = b[j] ^ nv;
        x = x ^ c[0][j];
    }
    c[0][0] = x;
    for(int j = 1;j<n;j++){
        c[j][0] = a[j] ^ mv;
    }
    for(int i =0;i<n;i++){
        for(int j =0;j < m;j++)cout << c[i][j] << " ";
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