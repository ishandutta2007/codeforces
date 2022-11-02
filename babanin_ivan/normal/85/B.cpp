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

int64 k1,k2,k3;
int64 t1,t2,t3;
int64 tek1,tek2,tek3;
int n;
int64 a[150000];
int64 ans=0;

set< pair<int64, pair<int,int>> > a1;

set < pair<int64,int> > sv1,sv2,sv3;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>k1>>k2>>k3;
    cin>>t1>>t2>>t3;
    tek1=k1;
    tek2=k2;
    tek3=k3;
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        a1.insert(mp(a[i],mp(0,i)));
        //a[i]=0;
    }
    while (!a1.empty() || !sv1.empty() || !sv2.empty() || !sv3.empty()){
        int64 tektime=(*a1.begin()).first;
        while (!a1.empty() && (*a1.begin()).first==tektime){
            pair <int,int> t=(*a1.begin()).second;
            a1.erase(a1.begin());
            if (t.first==0){
                sv1.insert(mp(0,t.second));
            }
            if (t.first==1){
                //a[t.second]+=t1;
                ++tek1;
                sv2.insert(mp(a[t.second],t.second));
            }
            if (t.first==2){
                //a[t.second]+=t2;
                ++tek2;
                sv3.insert(mp(a[t.second],t.second));
            }
            if (t.first==3){
                //a[t.second]+=t3;
                ++tek3;
                //sv2.insert(mp(a[t.second],t.second);
                if (ans<tektime-a[t.second])
                    ans=tektime-a[t.sec];
            }
        }
        while (tek1 && !sv1.empty()){
            --tek1;
            int t=(*sv1.begin()).second;
            a1.insert(mp(tektime+t1,mp(1,t)));
            sv1.erase(*sv1.begin());
        }
        while (tek2 && !sv2.empty()){
            --tek2;
            int t=(*sv2.begin()).second;
            a1.insert(mp(tektime+t2,mp(2,t)));
            sv2.erase(*sv2.begin());
        }
        while (tek3 && !sv3.empty()){
            --tek3;
            int t=(*sv3.begin()).second;
            a1.insert(mp(tektime+t3,mp(3,t)));
            sv3.erase(*sv3.begin());
        }
    }
    cout<<ans<<endl;
    return 0;
}