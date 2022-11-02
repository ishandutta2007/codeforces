#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;
const int treesz=131072;

int n;
int a[150000];
pair<int,int> b[150000];
int rmq[2*treesz+200];
int ans[150000];

void build(){
    for (int i=1;i<=2*treesz+100;++i)
        rmq[i]=inf;
}
void modify(int i){
    int j=i+treesz-1;
    rmq[j]=i;
    while (j!=1){
        j=j/2;
        rmq[j]=min(rmq[2*j],rmq[2*j+1]);
    }
}

int getmin(int l,int r,int i,int L,int R){
    if (r<L || R<l)
        return inf;
    if (l<=L && R<=r)
        return rmq[i];
    return min(getmin(l,r,2*i,L,(L+R)/2),getmin(l,r,2*i+1,((L+R)/2)+1,R));
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int x=0;
    int y=n-1;
    while (x<y){
        swap(a[x],a[y]);
        ++x;
        --y;
    }
    for (int i=0;i<n;++i){
        b[i].first=a[i];
        b[i].second=i;
    }
    build();
    sort(b,b+n);
    int l=0;
    while (l<n){
        int x=b[l].first;
        int r=l;
        while (r<n && b[r].first==x){
            int t=getmin(1,b[r].second+1,1,1,treesz);
            if (t==inf)
                ans[b[r].second]=-1;
            else ans[b[r].second]=b[r].second-t;
            ++r;
        }
        for (int i=l;i<r;++i)
            modify(b[i].second+1);
        l=r;
    }
    for (int i=n-1;i>=0;--i)
        printf("%d ",ans[i]);
    return 0;
}