#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = (ll)2e6+10;

ll v[MAXN];
ll t[MAXN];
ll a[MAXN];
ll out[MAXN];
deque<ll> o;
int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i =0;i<n;i++)cin >> a[i];
    ll ty, r;
    for(int i =0;i<m;i++){
        cin >> ty >> r;
        v[r-1]=ty;
        t[r-1] = i+1;
    }
    //cerr << " #@%";
    for(int i = n-2;i>=0;i--){
        if(t[i] < t[i+1]){
            t[i] = t[i+1];
            v[i] = v[i+1];
        }
    }
    ll l = -1;
    for(int i =n-1;i>=0;i--){
        if(v[i] == 0)out[i] = a[i];
        else{
            if(l == -1) l = i;
        }
    }
    //cout << l << endl;

    //cerr << " @";
    sort(a,a+l+1);
    for(int i =0;i<l+1;i++) o.pb(a[i]);
    //for(int i= 0;i<=l;i++)cout << a[i] << " " ;
    //cout << endl;
    for(int i = l;i>=0;i--){
        if(v[i] == 2){
            out[i] = o.front();
            o.pop_front();
        }else{
            out[i] = o.back();
            o.pop_back();
        }
    }
    for(int i =0;i<n;i++)cout << out[i] << " ";
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