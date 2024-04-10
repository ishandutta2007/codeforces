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
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;
const int hash=1000000007;

vector <int> a[500];
int n;
vector < pair<int,int> > b;
vector <int> ans[500];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i=0;i<n*(n-1)/2;++i){
        int k;
        scanf("%d",&k);
        for (int j=0;j<k;++j){
            int x;
            scanf("%d",&x);
            a[x].pb(i+1);
        }
    }
    for (int i=0;i<=200;++i)
        if (a[i].size()>0){
            int h=0;
            for (int j=0;j<a[i].size();++j)
                h=h*hash+a[i][j];
            b.pb(mp(h,i));
        }
    sort(b.begin(),b.end());
    int j=0;
    int k=0;
    for (int i=0;i<n;++i){
        if (j==b.size())
            break;
        ++k;
        while (j<b.size()-1 && b[j+1].first==b[j].first){
            ans[i].pb(b[j].second);
            ++j;
        }
        ans[i].pb(b[j].second);
        ++j;
    }
    if (k<n){
        int i=0;
        while (k<n){
            if (ans[i].size()>1 && k!=n){
                ans[k].pb(ans[i][ans[i].size()-1]);
                ans[i].pop_back();
                ++k;
                continue;
            }
            else ++i;
        }
    }
    for (int i=0;i<n;++i){
        printf("%d ",ans[i].size());
        for (int j=0;j<ans[i].size();++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }

    return 0;
}