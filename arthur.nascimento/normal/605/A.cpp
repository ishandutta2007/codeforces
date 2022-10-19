#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000009
#define maxn 200200

using namespace std;

map<int,int> cd;

vector<int> vv[maxn];

int bs(int num,int k){

    if(num == 0) 
        return 0;
    num = cd[num];
    if(vv[num].size() == 0)
        return 0;
    if(vv[num][0] > k)
        return 0;
    int low = 0, up = vv[num].size()-1;
    while(low != up){
        int mid = (low+up+1)/2;
        if(vv[num][mid] <= k)
            low = mid;
        else
            up = mid-1;
    }
    return 1+low;
}


main(){

    map<int,int> mp;
    int n;
    scanf("%d",&n);

    int r = 1;

    vector<pii> v;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(cd[a] == 0)
            cd[a] = r++;
        vv[cd[a]].pb(i);
        mp[a] = max(mp[a],i);
        v.pb(pii(a,-i));
    }

    sort(v.begin(),v.end());

    int ans = n;
    int cur = 0;
    int lastdif = -1;

    int cnt = 0;
    int last = 0;

    for(int i=0;i<n;i++){

        cnt++;
        int id = -v[i].second;
        if(id > lastdif)
            cur++;
        else
            cur = cnt + bs(last,id);
        if(v[i].first != v[i+1].first)
            lastdif = mp[v[i].first], cnt = 0, last = v[i].first;
        //last = id;
        debug("id %d cur %d\n",id,cur);
        ans = min(ans,n-cur);

    }

    printf("%d\n",ans);

}