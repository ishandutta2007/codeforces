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
#define mod 1000000007
#define maxn 200200

using namespace std;


pii hull[maxn];

long long ccw(pii a,pii b){
    return (long long )a.first*b.second - (long long)a.second*b.first;
}

long long ccw3(pii a,pii b,pii c){
    b.first -= a.first;
    b.second -= a.second;
    c.first -= a.first;
    c.second -= a.second;
    return ccw(b,c);
}

bool comp(pii a,pii b){
    if(ccw(a,b) == 0)
        return a.first < b.first;
    return ccw(a,b) >= 0;   
}

main(){
        
        int n;
        int p,q;
        scanf("%d%d%d",&n,&p,&q);
        
        vector<pii> v;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v.pb(pii(x,y));
        }
        
        sort(v.begin(),v.end(),comp);
            
        int len = 0;
        
        for(int i=0;i<n;i++){
                if(i)
                    if(v[i].first == v[i-1].first && v[i].second == v[i-1].second)
                        continue;
                debug("+ %d %d\n",v[i].first,v[i].second);
                hull[len++] = v[i];
                while(len >= 3){
                    if(ccw3(hull[len-3],hull[len-2],hull[len-1]) < 0){
                        debug("!%d\n",i);
                        swap(hull[len-1],hull[len-2]);
                        len--;
                    }
                    else break;
                }
    }
        long double ans = 999999999999999.0;
        hull[len++] = v[0];
        for(int i=0;i<len-1;i++){
        //  debug("%d %d - %d %d\n",hull[i].first,hull[i].second,hull[i+1].first,hull[i+1].second);
            long double low =0 , up = 999999999999999.0;
            long double A = hull[i].first, B = hull[i].second;
            long double C = hull[i+1].first, D = hull[i+1].second;
            if(A < C){
                    swap(A,C);
                    swap(B,D);
            }
            for(int j=0;j<100;j++){
                long double mid = (low+up)/2;
                int ok = 1;
                long double t = (long double)(p-mid*C)/(A-C);
                if(t > mid)
                    ok = 0;
                if(t < 0)
                    t = 0;
                if( t*B + (mid-t) * D < q)
                    ok = 0;
                if(ok)
                    up = mid;
                else
                    low = mid;
            }
            if(low < ans)
                ans = low;
        
    }
    for(int i=0;i<len;i++){
            //debug("%d %d - %d %d\n",hull[i].first,hull[i].second,hull[i+1].first,hull[i+1].second);
            long double low =0 , up = 999999999999999.0;
            long double A = hull[i].first, B = hull[i].second;
            long double C = hull[i].first, D = hull[i].second;
            if(A < C){
                    swap(A,C);
                    swap(B,D);
            }
            for(int j=0;j<100;j++){
                long double mid = (low+up)/2;
                int ok = 1;
                long double t = (long double)(p-mid*C)/(A-C);
                if(t > mid)
                    ok = 0;
                if(t < 0)
                    t = 0;
                if( t*B + (mid-t) * D < q)
                    ok = 0;
                if(ok)
                    up = mid;
                else
                    low = mid;
            }
            if(low < ans)
                ans = low;
        
    }
    
        printf("%.14lf\n",(double)ans);
        
}