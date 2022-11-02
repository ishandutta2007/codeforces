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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int pos[100];
int d[100];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n,k;
    int kol;
    scanf("%d %d %d",&kol,&n,&k);
    for (int i=0;i<n;i++)
        scanf("%d",&d[i]);      
    for (int i=0;i<k;i++)
        scanf("%d",&pos[i]);
    int bcnt=1<<30;
    vector<int> ans;
    for (int i=0;i<n;i++){
        int cnt=0;
        for (int j=0;j<k;j++)
            if (pos[j]%d[i]==0)
                cnt++;          
        if (cnt<bcnt){
            ans.clear();
            bcnt=cnt;
        }
        if (cnt==bcnt)
            ans.pb(i);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;     
    return 0;
}