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

int n,m;
ld w,x;

void printerr(){
    cout<<"NO\n";
    exit(0);
}

vector <pair <int,ld> > ans[100];
ld but[100];
ld kru[100];
int kol[100];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>w>>m;
    x=(ld(n)*w)/ld(m);
    if (w>(2*x))
        printerr();
    int tekn=0;
    int tekm=0;
    for (int i=0;i<n;++i)
        but[i]=w;
    for (int i=0;i<m;++i)
        kru[i]=x;
    if (w>x){
        for (int i=0;i<n;++i){
            but[i]-=kru[i];
            kru[i]=0;
            ans[i].pb(mp(i+1,x));
        }
    }
    
    for (int i=0;i<m;++i){
        while (kru[i]>eps){
            if (but[tekn]<eps)
                tekn++;
            ld y=min(but[tekn],kru[i]);
            but[tekn]-=y;
            kru[i]-=y;
            ans[i].pb(mp(tekn+1,y));
        }
    }
    for (int i=0;i<m;++i)
        for (int j=0;j<ans[i].size();++j)
            ++kol[ans[i][j].first-1];
    for (int i=0;i<n;++i)
        if (kol[i]>2)
            printerr();

    cout<<"YES"<<endl;
    cout.precision(10);
    for (int i=0;i<m;++i){
        for (int j=0;j<ans[i].size();++j){
            cout<<ans[i][j].first<<" "<<fixed<<ans[i][j].second<<" ";
        }
        printf("\n");
    }
    return 0;
}