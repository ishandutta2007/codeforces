#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (int)1e9;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
map<string, int> id;
int sz;
vector<int> g[1111];
vector<int> gr[1111];
int type[1111];
int C[1111];
int D[1111];
string a[1111];

int get_id(string x){
    if(id.count(x) == 0){
        id[x] = sz;
        a[sz] = x;
        sz++;
    }
    return id[x];
}

int toNumber(string x){
    int n = 0;
    for(int i = 0 ; i< x.size(); i++){
        n = n * 10 + x[i] - '0';
    }
    return n;
}

void addWidget(string s){
    int ind = 0;
    while(s[ind] != '(') ind++;
    int ind2 = ind;
    while(s[ind2] != ',') ind2++;
    string name = s.substr(0, ind);
    string x = s.substr(ind+1, ind2 - ind - 1);
    string y = s.substr(ind2+1, s.size() - ind2 - 2);

    int I = get_id(name);
    type[I] = 0;
    C[I] = toNumber(x);
    D[I] = toNumber(y);
    return;
}
void addHBox(string s){
    int I = get_id(s);
    type[I] = 1;
}
void addVBox(string s){
    int I = get_id(s);
    type[I] = 2;
}

void addPack(string s, string x){
    int a = get_id(s);
    int b = get_id(x);
    g[a].pb(b);
    gr[b].pb(a);
}
void setBorder(string s, string x){
    int y = toNumber(x);
    int I = get_id(s);
    D[I] = y;
}
void setSpacing(string s, string x){
    int y = toNumber(x);
    int I = get_id(s);
    C[I] = y;
}

vector< pair<string, pll> > ans;
ll A[1111];
ll B[1111];
int used[1111];
void dfs(int v){
    if(used[v]) return;
    used[v] = 1;
    if(type[v] == 0){
        A[v] = C[v];
        B[v] = D[v];
    }else if(type[v] == 1){
        A[v] = 0;
        B[v] = 0;
        ll sum = 0;
        ll mx = 0;
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            dfs(to);
            sum += A[to];
            mx = max(B[to], mx);
        }
        if(g[v].size() > 0){
            A[v] = C[v] * (g[v].size()-1) + sum + 2 * D[v];
            B[v] = mx + 2 * D[v];
        }
    }else if(type[v]==2){
        A[v] = 0;
        B[v] = 0;
        ll sum = 0;
        ll mx = 0;
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i];
            dfs(to);
            sum +=B[to];
            mx = max(A[to], mx);
        }
        if(g[v].size() > 0){
            B[v] = C[v] * (g[v].size()-1) + sum + 2 * D[v];
            A[v] = mx + 2 * D[v];
        }
    }
    ans.pb(mp(a[v], mp(A[v], B[v])));
}


void solve(){
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int ok = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '.') ok = 1;
        }
        if(ok){
            int ind = 0;
            while(s[ind] != '.') ind++;
            int ind2 = 0;
            while(s[ind2] != '(') ind2++;
            string type = s.substr(ind+1, ind2-ind-1);
            string ope = s.substr(ind2+1, s.size() - ind2 - 2);
            if(type == "pack"){
                addPack(s.substr(0, ind), ope);
            }else if(type == "set_border"){
                setBorder(s.substr(0, ind), ope);
            }else{
                setSpacing(s.substr(0, ind), ope);
            }
        }
        else{
            int ind = 0;
            while(s[ind] != ' ') ind++;

            if(s.substr(0, ind) == "Widget"){
                addWidget(s.substr(ind+1));
            }else if(s.substr(0, ind) == "HBox"){
                addHBox(s.substr(ind+1));
            }else{
                addVBox(s.substr(ind+1));
            }
        }
    }
    for(int i = 0 ; i <sz; i++){
        if(gr[i].size() == 0){
            dfs(i);
        }
    }
    sort(all(ans));
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i].f << " "<< ans[i].s.f << " "<< ans[i].s.s << endl;
    }
}

int main () {
    #ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}