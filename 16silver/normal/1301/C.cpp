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
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        long long n,m;
        scanf("%lld%lld",&n,&m);
        long long q=(n-m)/(m+1),r=(n-m)%(m+1);
        printf("%lld\n",n*(n+1)/2-r*(q+1)*(q+2)/2-(m+1-r)*q*(q+1)/2);
    }
}