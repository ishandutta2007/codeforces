#include <bits/stdc++.h>
#define maxn 1001000
#define pb push_back
#define pii pair<int,int>
#define debug 
using namespace std;
 
int v[maxn];
 
int val[maxn];
vector<int> ans[maxn];
 
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int s = 0;
    for(int i=0;i<m;i++)
        scanf("%d",v+i), s += v[i];
    while(s%n) v[0]++, s++;
    printf("%d\n",s/n);
    int resp = s/n;
    set<pii> S;
    int at = 0;
    for(int i=0;i<m;i++)
        S.insert(pii(v[i],i));
    while(at < m){
        assert(s%n == 0);
        debug("at %d n %d s %d\n",at,n,s);if(S.size() == 0) break;
      //  for(set<pii> :: iterator it = S.begin(); it != S.end(); it++)
        //    debug("-> %d %d\n",it->first,it->second);
        debug("\n");
        while(S.size() > 0 && (--S.end())->first >= n){
            pii u = *--S.end();
            S.erase(u);
            u.first -= n;
            s -= n;
            if(u.first) S.insert(u);
            for(int i=at;i<m;i++)
                ans[i].pb(u.second);
            debug("%d..%d atk %d\n",at+1,m,u.second+1);
        } if(S.size() == 0) break;
        pii u = *S.begin();
        val[at] = u.first;
        debug("%d is %d\n",at+1,val[at]);
        vector<pii> novos;
        int ii = 0;
        for(set<pii> :: iterator it = S.begin(); ii < s/n; it++, ii++){ if(it == S.end()) break;
            if(it->first > u.first) novos.pb(pii(it->first-u.first,it->second));
            ans[at].pb(it->second);   debug("%d atk %d\n",at+1,it->second+1);
        }
        assert(ii == s/n);
        for(ii=0;ii<s/n && S.size() > 0;ii++) S.erase(S.begin());
        for(ii=0;ii<novos.size();ii++) S.insert(novos[ii]);
        s -= (s/n) * u.first;
        n -= u.first;
       
        at++;
    }
    if(n) val[m-1] += n;
    for(int i=0;i<m;i++)
        printf("%d ",val[i]);
    printf("\n");
    for(int i=0;i<m;i++)
        while(ans[i].size() < resp) ans[i].pb(0);
    for(int i=0;i<resp;i++){
        for(int j=0;j<m;j++)
            printf("%d ",ans[j][i]+1);
        printf("\n");
    }
}