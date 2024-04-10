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

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int resx=0;
    int resy=0;
    int resz=0;
    for (int i=0;i<n;++i){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        resx+=x;
        resy+=y;
        resz+=z;
    }
    if (resx==0 && resy==0 && resz==0)
        cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}