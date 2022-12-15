#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,q;
int arr[12],cnt[1<<12],cache[1<<12][101];

char str[20];

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

    for(int i=0;i<m;i++) {
        scanf("%s",str);

        int val=0;
        for(int i=0;i<n;i++) val=val*2+(str[i]-'0');
        cnt[val]++;
    }
    reverse(arr,arr+n);
    for(int i=0;i<1<<n;i++) for(int j=0;j<1<<n;j++) {
        int s=i^j,sum=0;
        for(int k=0;k<n;k++) if(!(s>>k&1)) {
            sum+=arr[k];
        }
        if(sum<=100) cache[i][sum]+=cnt[j];
    }
    for(int i=0;i<1<<n;i++) {
        for(int j=1;j<=100;j++) cache[i][j] += cache[i][j-1];
    }
    while(q--) {
        int k,val=0;
        scanf("%s%d",str,&k);
        for(int i=0;i<n;i++) 
            val=val*2+str[i]-'0';

        printf("%d\n",cache[val][k]);
    }
    return 0;
}