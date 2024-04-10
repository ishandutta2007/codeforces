#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back

int n,y,x;
int a[100100];
int ans[100100];
vector <int> b;
map <int,int> used;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    scanf("%d %d",&x,&y);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        b.pb(a[i]);
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for (int i=0;i<min(x,y);++i)
        ++used[b[i]];
    if (x==y){
        for (int i=0;i<x;++i)
            printf("1 ");
        for (int i=0;i<y;++i)
            printf("2 ");
        return 0;
    }
    if (x<y){
        for (int i=0;i<n;++i)
            if (used.find(a[i])!=used.end() && used[a[i]]){
                --used[a[i]];
                printf("1 ");
            }
            else printf("2 ");
    }
    else {
        for (int i=n-1;i>=0;--i)
            if (used.find(a[i])!=used.end() && used[a[i]]){
                --used[a[i]];
                ans[i]=2;
            }
            else ans[i]=1;
        for (int i=0;i<n;++i)
            printf("%d ",ans[i]);
    }
}