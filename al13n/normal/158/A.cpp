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

int n;
int src[1000000];

#define taska "reverse2d"
int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

    int k;
    cin>>n>>k;
    forn(i,n){
        cin>>src[i];
    }
    --k;
    int r=0;
    forn(i,n){
        if(src[i]>=src[k]&&src[i])
            ++r;
    }
    cout<<r;
	
	return 0;
}