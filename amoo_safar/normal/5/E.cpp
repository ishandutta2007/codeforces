#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll)1e9 + 7;
const ll MAXN = (ll)1e6 + 10;
const ll INF = (ll) 9223372036854775807;

stack<ll> s;
stack<ll> t;

ll a[MAXN];
ll b[MAXN];
ll dp[MAXN];

ll rb[MAXN];
ll rbb[MAXN];

int fl[MAXN];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ind = 0;
    for(int i =0;i<n;i++){
        if(a[ind] < a[i])ind = i;
    }
    /*for(int i = 0; i < ind;i++){
        for(int j =0;j<n-1;j++)swap(a[j],a[j+1]);
    }*/
    for(int i = 0;i<n;i++)b[i] = a[(ind + i) % n];

    /*for(int i=0;i<n;i++)cerr << b[i] << " ";
    cerr << endl;*/

    for(int i = 0; i < n; i++)a[i] = b[i];
    ll cnt = 0;
    ind = 1;
    for(int i = 1 ;i < n;i++){
        if(a[ind] <= a[i]){
            ind = i;
            cnt ++;
            fl[ind] = 1;
        }
    }
    ind = n - 1;
    for(int i = n - 1;i > 1;i--){
        if(a[i] >= a[ind]){
            ind = i;
            if(fl[ind] == 0){
                fl[ind] = 1;
                cnt++;
            }
        }
    }
    //debug(cnt);
    a[n] = INF;

    s.push(n);
    for(int i = n - 1; i > 0; i--){
        while(a[s.top()] < a[i]) s.pop();
        rb[i] = s.top();
        s.push(i);
    }


    t.push(n);
    for(int i = n - 1; i > 0; i--){
        while(a[t.top()] <= a[i]) t.pop();
        rbb[i] = t.top();
        t.push(i);
    }
    /*
    cerr << n << " ";
    for(int i = 1;i < n;i++)cerr << rb[i] << " ";
    cerr << endl;

    cerr << n << " ";
    for(int i = 1;i < n;i++)cerr << rbb[i] << " ";
    cerr << endl;*/



    dp[n] = 0;
    for(int i = n - 1; i > 0; i--) dp[i] = 1 + dp[rb[i]];

    //for(int i = 0;i < n;i++)cerr << dp[i] << " ";
    //cerr << endl;

    for(int i = 1;i < n;i++){
        if(rbb[i] != n)cnt += 1 + (dp[i + 1] - dp[rbb[i]]);
        else cnt += dp[i + 1];
        //debug(cnt);
    }
    //for(int i = 1;i<n;i++){
    //    if(rbb[i] == n)cnt --;
    //}
    cout << cnt;
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