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
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;

pair<pair<int,int> , int > a[1100];

set<pair<int,int> > s;

int date[1100];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d %d",&a[i].first.first,&a[i].first.second);
        a[i].second=i;
    }
    sort(a,a+n);
    int ptr=0;
    int time=0;
    for (;ptr<n || !s.empty();){
        if (s.empty())
            time=a[ptr].first.first;
        for (;ptr<n && a[ptr].first.first==time;++ptr)
            s.insert(mp(a[ptr].first.second,a[ptr].second));
        int ans=s.begin()->second;
        s.erase(s.begin());
        date[ans]=time;
        time++;
    }
    for (int i=0;i<n;i++)
        printf("%d ",date[i]);
    printf("\n");
    return 0;
}