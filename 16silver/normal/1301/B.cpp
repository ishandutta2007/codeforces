#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int a[111111];

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans=0,xx=2000000000,yy=-1;
        for(int i=1;i<n;i++){
            if(a[i-1]==-1){
                if(a[i]!=-1){
                    xx=min(xx,a[i]);
                    yy=max(yy,a[i]);
                }
            }
            else{
                if(a[i]==-1){
                    xx=min(xx,a[i-1]);
                    yy=max(yy,a[i-1]);
                }
                else{
                    ans=max(ans,max(a[i]-a[i-1],a[i-1]-a[i]));
                }
            }
        }
        printf("%d %d\n",max(ans,(yy-xx+1)/2),(xx+yy)/2);
    }
}