#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

vector<pair<int,int> > v;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v.pb(mp(a,b));
    }
    if(n%2!=0){
        puts("NO");
        return 0;
    }
    else{
        int xxx=v[0].x+v[n/2].x, yyy=v[0].y+v[n/2].y;
        for(int i=1;i<n/2;i++){
            if(v[i].x+v[n/2+i].x!=xxx || v[i].y+v[n/2+i].y!=yyy){
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        return 0;
    }
}