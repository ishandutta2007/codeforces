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

int n;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&n);
    int i=5;
    int j=1;
    int k=5;
    int st=1;
    while (i<n){
        j=j*2;
        k=k*2;
        st=i+1;
        i+=k;
    }
    n=n-st;
    int tek=0;
    int kz=j-1;
    int ans;
    for (ans=0;ans<5;++ans){
        if (n<=kz)
            break;
        tek+=j;
        kz+=j;
    }
    if (ans==0)
        printf("Sheldon");
    if (ans==1)
        printf("Leonard");
    if (ans==2)
        printf("Penny");
    if (ans==3)
        printf("Rajesh");
    if (ans==4)
        printf("Howard");
    return 0;
}