#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define ends asdends
#define PII pair<int,int>
#define X first
#define Y second



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

    lng q;
    cin>>q;
    lng qq=q;
    lng res=1;
    int cnt=0;
    for(lng i=2;i*i<=qq;++i){
        while(qq%i==0){
            qq/=i;
            ++cnt;
            res*=i;
            if(cnt==2)
                break;
        }
        if(cnt==2)
            break;
    }
    if(qq>1&&cnt<2){
        ++cnt;
        res*=qq;
    }
    if(cnt<2||cnt==2&&res!=q){
        if(cnt<2)
            res=0;
        cout<<"1\n"<<res;
    }else{
        cout<<2;
    }

    return 0;
}