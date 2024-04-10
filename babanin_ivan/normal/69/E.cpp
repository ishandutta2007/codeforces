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

int n,k;
int a[100100];

set <int> one;
map <int, int> kol;

void printerr(){
    printf("Nothing\n");
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);

    for (int i=1;i<=k;++i){
        one.insert(a[i]);
        ++kol[a[i]];
    }
    set <int> :: iterator it;
    it=one.begin();
    set <int > one2=one;

    while (it != one.end()){
        if (kol[*it]>1)
            one2.erase(*it);
        ++it;
    }
    one=one2;
    if (!one.empty())
        printf("%d\n",*one.rbegin());
    else printerr();
    
    for (int j=k+1;j<=n;++j){
        --kol[a[j-k]];
        if (kol[a[j-k]]==0)
            one.erase(a[j-k]);
        if (kol[a[j-k]]==1)
            one.insert(a[j-k]);
        ++kol[a[j]];
        if (kol[a[j]]==2)
            one.erase(a[j]);
        if (kol[a[j]]==1)
            one.insert(a[j]);
        if (!one.empty())
            printf("%d\n",*one.rbegin());
        else printerr();
    }
    return 0;
}