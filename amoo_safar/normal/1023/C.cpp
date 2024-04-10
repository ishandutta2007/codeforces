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

stack<ll> s;
ll f[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,k;
    cin >> n >> k;
    str st;
    cin >> st;
    for(int i =0;i<n;i++){
        if(k == 0)break;
        if(st.size() == 0){
            if(st[i] == '(') s.push(i);
        }else{
            if(st[i] == '(') s.push(i);
            else{
                if(st[s.top()] == '('){
                    f[i] = 1;
                    f[s.top()] = 1;
                    k -= 2;
                    s.pop();
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(f[i] == 1)cout << st[i];
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