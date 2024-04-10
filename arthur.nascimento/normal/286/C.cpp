#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int v[1001000];
int ss[1001000];

int ans[1001000];

main(){
        
        int n;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
            scanf("%d",v+i);
            
        int k;
        scanf("%d",&k);
        
        for(int i=0;i<k;i++){
            int a;
            scanf("%d",&a);
            ss[a-1] = 1;
        } 

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            
            if(st.size() && !ss[i] && v[i] == st.top())
                st.pop(),
                ans[i] = 1;
            else
                st.push(v[i]),
                ans[i] = -1;
                
        }
        
        if(st.size() == 0){
            printf("YES\n");
            for(int i=0;i<n;i++)
                printf("%d ",ans[i] * v[i]);
        }
        
        else
            printf("NO\n");
            
}