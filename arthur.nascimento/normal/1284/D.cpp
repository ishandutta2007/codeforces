#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define debug 
#define pip pair<pii,int>
#define pii pair<int,int>
using namespace std;
 
ll fat[maxn];

vector<int> go(vector<pip> v){
    int n = v.size();
    vector<pii> ini,fim;
    for(int i=0;i<n;i++){
        int l = v[i].first.first, r = v[i].first.second, u = v[i].second;
        ini.pb(pii(-l,u));
        fim.pb(pii(r,u));
    }
    
    sort(ini.begin(),ini.end());
    sort(fim.begin(),fim.end());
    
    for(int i=1;i<n;i++){
        ini[i].second ^= ini[i-1].second;
        fim[i].second ^= fim[i-1].second;
    }
    
    vector<int> ans;
    for(int i=0;i<n;i++){
        int l = v[i].first.first, r = v[i].first.second, u = v[i].second;
        int x = 0;
        vector<pii> :: iterator it1 = lower_bound(ini.begin(), ini.end(), pii(-r,-1)); //ini.lower_bound(pii(l,-1));
        if(it1 != ini.begin()){
            it1--;
            x ^= it1->second;
        }
        vector<pii> :: iterator it2 = lower_bound(fim.begin(), fim.end(), pii(l,-1));
        if(it2 != fim.begin()){
            it2--;
            x ^= it2->second;
        }
        debug("x %d\n",x);
        
        ans.pb(x);
        
    }
    
    debug("--\n");
    return ans;
    
}

int main() {
    int n;
    scanf("%d",&n);
    vector<pip> v1,v2;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int u = rand();
        v1.pb(pip(pii(a,b),u));
        v2.pb(pip(pii(c,d),u));
    }
    vector<int> A = go(v1);
    vector<int> B = go(v2);
    for(int i=0;i<n;i++)
        if(A[i] != B[i]){
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
}