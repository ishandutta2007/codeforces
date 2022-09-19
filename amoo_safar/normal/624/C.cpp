#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const long MOD = (long)1e9 + 7;
ll const MAXN = 400010;

ll c[500];
ll d[500];

vector<int> a[500];

ll fl = 0;
void dfs(ll node,ll col){
    for(int i= 0;i<a[node].size();i++){
        if(c[a[node][i]] == 0){
            c[a[node][i]] = col;
            dfs(a[node][i],col);
        }else{
            if((c[a[node][i]]!= col) and (c[a[node][i]]!=1)){
                fl =1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);//cin.tie(0);cout.tie(0);
    //cout.precision(16);
    ll n,m;
    cin >> n >> m;
    ll u,v;
    for(int i =0;i<m;i++){
        cin >> u >> v;
        u--;
        v--;
        d[u]++;
        d[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i =0;i<n;i++){
        if(d[i] == n-1) c[i] = 1;
    }
    ll co = 2;
    for(int i =0;i<n;i++){
        if(c[i] == 0){
            c[i] = co;
            dfs(i,co);
            co++;
        }
    }
    ll c1=0,c2=0,c3=0;
    ll d1=0,d2=0,d3=0;

    if(co > 4 or fl == 1){
        cout << "No";
        return 0;
    }
    for(int i =0;i<n;i++){
        if(c[i] == 1)c1++;
        if(c[i] == 2)c2++;
        if(c[i] == 3)c3++;
    }
    for(int i =0;i<n;i++){
        if(c[i] == 2){
            if(d[i] !=(c1+c2-1)){
                cout << "No";
                return 0;
            }
        }
        if(c[i] == 3){
            if(d[i] !=(c1+c3-1)){
                cout << "No";
                return 0;
            }
        }
    }

    //for(int i =0;i<n;i++)cout << c[i];
    cout << "Yes" << endl;;
    for(int i =0;i<n;i++){
        if(c[i] == 1)cout << "b";
        else{
            if(c[i] == 2)cout << "a";
            else cout << "c";
        }
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