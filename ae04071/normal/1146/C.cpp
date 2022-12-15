#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;

int v[8]={50,25,20,10,5,4,2,1};
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n;
        scanf("%d",&n);
        
        int d=0;
        for(int i=0;i<8;i++) {
           vector<int> arr[2];
           for(int j=0;j<n;j++) arr[j/v[i]%2].push_back(j+1);
           if(sz(arr[1])==0) continue;
           
            printf("%d %d",sz(arr[0]),sz(arr[1]));
            for(auto &v:arr[0]) printf(" %d",v);
            for(auto &v:arr[1]) printf(" %d",v);
            puts("");
            fflush(stdout);
            
            int td=0;
            scanf("%d",&td);
            d = max(d,td);
        }
        printf("-1 %d\n",d);
        fflush(stdout);
    }
    return 0;
}