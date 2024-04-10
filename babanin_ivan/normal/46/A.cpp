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
    scanf("%d",&n);
    int tekboy=1;
    for (int i=0;i<n-1;++i){
        tekboy=tekboy+i+1;
        if (tekboy>n)
            tekboy-=n;
        printf("%d ",tekboy);
    }
}