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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

main(){
       
       int n;
       long long maior = 0;
       long long S = 0;
       scanf("%d",&n);
       
       for(int i=0;i<n;i++){
               long long k;
               cin >> k;
               maior = max(maior,k);
               S += k;}
               
       if(S % (n-1) == 0)
            cout << max(maior,S / (n-1)) << endl;
       else cout << max(maior,1 + S / (n-1)) << endl;
       
       }