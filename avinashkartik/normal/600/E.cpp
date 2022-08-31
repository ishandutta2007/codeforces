#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e9;
const int N = 1e5+3;

ll a[N],vis[N],ans[N],m1[N];
string s;
vector <ll> v[N];
ll t,n,ct,q,k,U,V,i,j,flag,u,sum;
set <ll> se;
pair <ll,ll> p;
map <ll,ll> m[N];

void dfs(ll x){
    if(!vis[x]){
        vis[x] = 1;
        for(auto it : v[x]){
            if(!vis[it]){
                dfs(it);
                if (m[it].size() > m[x].size()) {
                    swap(m[it], m[x]);
                    ans[x] = ans[it];
                    m1[x] = m1[it];
                }
                for(auto i : m[it]){
                    m[x][i.first] += i.second;
                    ll res = m[x][i.first];
                    if(res > m1[x]){
                        ans[x] = i.first;
                        m1[x] = res;
                    }
                    else if(res == m1[x]){
                        ans[x] += i.first;
                    }
                //cout<<x<<" "<<it<<" "<<endl;
                }
                m[it].clear();
            }
        }
        m[x][a[x]]++;
        if(m[x][a[x]] > m1[x]){
            ans[x] = a[x];
            m1[x] = m[x][a[x]];
        }
        else if(m[x][a[x]] == m1[x]){
            ans[x] += a[x];
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i < n; i++){
        cin>>U>>V;
        v[U].push_back(V);
        v[V].push_back(U);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
}