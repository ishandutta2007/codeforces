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

set<pair<int,int> > a;
set<int> b;

int skil[300000];
char s[300000];
int n;

vector<int> fi,se;

void get(){
    int pos=a.begin()->second;
    int pos1=*b.upper_bound(pos);
    a.erase(a.begin());
    fi.pb(pos);
    se.pb(pos1);
    b.erase(pos);
    b.erase(pos1);
    set<int>::iterator next=b.upper_bound(pos1);
    if (next!=b.end()){
        int v=*next;
        if ((s[pos1]=='B') ^ (s[v]=='B'))
            a.erase(mp(abs(skil[v]-skil[pos1]),pos1));
    }
    set<int>::iterator prev=b.lower_bound(pos);
    if (prev==b.begin())
        return;
    --prev;
    int v=*prev;
    if ((s[v]=='B') ^ (s[pos]=='B'))
        a.erase(mp(abs(skil[v]-skil[pos]),v));
    if (next!=b.end()){
        int v2=*next;
        if ((s[v]=='B') ^ (s[v2]=='B'))
            a.insert(mp(abs(skil[v2]-skil[v]),v));      
    }
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d\n",&n);
    gets(s);
    for (int i=0;i<n;i++){
        scanf("%d",&skil[i]);
        b.insert(i);
    }
    for (int i=0;i<n-1;i++)
        if ((s[i]=='B') ^ (s[i+1]=='B'))
            a.insert(mp(abs(skil[i]-skil[i+1]),i));
        
    for (;!a.empty();){
        get();
    }
    
    int sz=fi.size();
    printf("%d\n",sz);
    
    for (int i=0;i<sz;i++)
        printf("%d %d\n",fi[i]+1,se[i]+1);      
    return 0;
}