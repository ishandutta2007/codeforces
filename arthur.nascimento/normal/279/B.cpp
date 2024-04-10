#include <cstdio>
#include <algorithm>
#define MAX 100100

using namespace std;


int main(){

    int n, t,v[MAX],acu[MAX];
    scanf("%d %d",&n,&t);
    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);
    

    acu[0] = 0;
    for(int i = 1; i <= n; i++)
        acu[i] = acu[i-1] + v[i-1];

    int max = 0;    
    for(int i = 0; i < n; i++){
        int lo, hi;
        lo = i+1;
        hi = n;
        while(lo < hi){
            int mid = (lo+hi+1)/2;
            if(acu[mid] - acu[i] <= t)
                lo = mid;               
            else
                hi = mid-1;
        }
        if(hi-i > max && acu[lo] - acu[i] <= t)
            max = hi-i;
    }
    printf("%d\n",max);
            
}