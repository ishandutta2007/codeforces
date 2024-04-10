#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <ctime>
#include <memory.h>
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define forv(i, a) for(int i=0; i<(int)a.size(); i++)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define VI vector< int >
#define VS vector< string >
#define PII pair< int,int >
#define PDD pair< double,double >
#define PIS pair< int, string >
#define sqr(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define pi 3.1415926535897932384626433832795
#define iinf 1000000000
#define sinf 10000
#define eps 1e-12
#define lng long long
#define X first
#define Y second
#define max asdmax
#define min asdmin
using namespace std;
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }
template<class T> inline T asdmax(T a, T b){return a>b?a:b;}template<class T> inline T asdmin(T a, T b){return a<b?a:b;}

int T[4100];
int D[4100];
int n,K;
int dp[4100];

#define taska "reverse2d"
int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

    cin>>n>>K;
    forn(i,n){
        cin>>T[i]>>D[i];
        --T[i];
    }
    T[n]=86400;
    forn(i,n+1){
        dp[i]=iinf;
    }
    dp[0]=0;
    int res=0;
    forn(q,n+1){
        for(int c=q;c>=0&&c>=q-K;--c){
            res=max(res,T[min(n,K+c)]-dp[c]);
            dp[c]=max(T[q],dp[c]);
            dp[c+1]=min(dp[c+1],dp[c]+D[q]);
        }
    }
    cout<<res;
	
	return 0;
}