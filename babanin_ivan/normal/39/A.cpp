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

struct coef{
    int c;
    bool pref;
};

bool first;

bool read(coef& a){
    if (first){ 
        char C;
        scanf(" ");
        C=getc(stdin);
        ungetc(C,stdin);
        if (C<='9' && C>='0'){
            scanf(" %d ",&a.c);
            scanf("*");
        }
        else
            a.c=1;
        first=false;    
    }
    else {
        char sign;
        int tmp=scanf(" %c ",&sign);
        if (tmp==EOF)
            return false;       
        scanf(" ");
        char C;
        C=getc(stdin);
        ungetc(C,stdin);
        if (C<='9' && C>='0'){
            scanf(" %d ",&a.c); 
            scanf("*");
        }
        else
            a.c=1;
        if (sign=='-')
            a.c*=-1;
    }
    char c;
    if (scanf("++%c",&c)==1){
        assert(c=='a');
        a.pref=true;        
    }
    else {
        scanf("a++");
        a.pref=false;
    }
    return true;
}

bool operator<(const coef& a,const coef& b){
    if (a.c==b.c){
        if (b.pref)
            return false;
        if (a.pref)
            return true;
        return false;           
    }
    return a.c<b.c;
}

coef cs[1000];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int a;
    scanf("%d",&a);
    int ptr=0;
    for (first=true;read(cs[ptr]);++ptr);
    sort(cs,cs+ptr);
    int64 ans=0;
    for (int i=0;i<ptr;i++){
    //  cerr<<cs[i].c<<" "<<cs[i].pref<<endl;
        a+=cs[i].pref;
        ans+=a*1LL*cs[i].c;
        a+=!cs[i].pref;
    }
    cout<<ans<<endl;
    return 0;
}