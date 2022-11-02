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

int n;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b;
    scanf("%d %d",&a,&b);
    int x=a;
    int y=b;
    int max1=-1;
    int max2=-1;
    while (x!=0){
        max1=max(max1,x%10);
        x=x/10;
    }
    while (y!=0){
        max2=max(max2,y%10);
        y=y/10;
    }
    
    //a=a+b;
    int maxsz=-1;
    int max3=max(max1+1,max2+1);
    for (int j=max3;j<=3000;++j){
        int x=a;
        int y=b;
        int sz=0;
        int ost=0;
        while (x!=0 || y!=0){
            ost=(x%10)+(y%10)+ost;
            x=x/10;
            y=y/10;
            ++sz;
            ost=ost/j;
        }
        if (ost>0)++sz;
        maxsz=max(sz,maxsz);
    }
    printf("%d",maxsz);
}