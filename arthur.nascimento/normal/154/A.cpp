#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 100100		
#define mod 1000000007
 
using namespace std;

char str[maxn];

int r[200];

main(){
        
        for(int i='a';i<='z';i++)
                r[i] = i;
         
        scanf(" %s",str);
        
        int q;
        scanf("%d",&q);
        while(q--){
                char a,b;
                scanf(" %c%c",&a,&b);
                r[a] = r[b] = q;
        }
        
        int p = 0;
        int n = strlen(str);
        int ans = 0;
        while(p < n){
                int p0 = p;
                map<int,int> mp;
                while(p < n && r[str[p]] == r[str[p0]]){
                        mp[str[p]]++;       
                        p++;
                }
                int qnt = 0, men = 999999;
                for(int i='a';i<='z';i++)
                        if(mp[i]) qnt++, men = min(men,mp[i]);
                if(qnt > 1) ans += men;
                debug("%d ~ %d\n",p0,p-1);
        }
        
        cout << ans << endl;

}