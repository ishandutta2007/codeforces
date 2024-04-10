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
#define int64 long long       
#define ld long double

const int inf=2000000000;

void printerr(){
    printf("0 0\n");
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    int a[2000];
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int i=0;
    while (i<n-1 && a[i+1]-a[i]==1)
        ++i;
    if (i==n-1)
        printerr();
    int l=i+1;
    if (a[i]-a[i+1]==1)
        l=i;
    else l=i+1;
    int r=l;
    while (r<n-1 && a[r]-a[r+1]==1)
        ++r;
    if (!(l<r))
        printerr();
    i=r+1;
    bool f=true;
    for (;i<n-1;++i)
        if ((a[i+1]-a[i])!=1)
            f=false;
    ++l;
    ++r;
    if (f)
        printf("%d %d",l,r);
    else printerr();
    return 0;
}