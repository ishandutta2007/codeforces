#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = 400010;

ll c[1001];

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    str s,t;
    cin >> s >> t;
    int f;
    ll cn  =0 ;
    for(int i = 0;i<n-m+1;i++){
        f = 1;
        for(int j = i;j<i+m;j++){
            if(s[j] != t[j - i]) f=0;
        }
        //cout << f << "   "<< i << endl;
        if(f == 1)c[i] = 1;
    }
    ll l,r,cnt;
    for(int i =0;i<q;i++){
        cin >> l >>r;
        cnt = 0;
        for(int j = l;j <= r-m+1;j++){
            //cout << j << " ";
            cnt += c[j-1];
        }
        cout << cnt << endl;
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