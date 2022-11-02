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
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;


int p[18100000];
int primes[2000000];
int prkol;

void calc(int sum){ 
//  cerr<<sum<<"\n"<<18000000<<endl;
    for (int i=2;i<=sum;i++){
        if (p[i]==0){
            primes[prkol++]=i;
            p[i]=i;
    //      if (prkol%1000000==0)
    //          cerr<<prkol<<endl;
                
        }
        for (int j=0;j<prkol && primes[j]<=p[i] && primes[j]*1LL*i<=sum;j++)
            p[primes[j]*i]=primes[j];
    }
}

bool check(int n){
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return false;
    return true;
}

int color[6100];

void solve2(int sum){
    int p1=-1,p2;
//  cerr<<sum<<endl;
    for (int i=2;i<=sum-2;i++){
        if (p[i]==i && p[sum-i]==sum-i){
            p1=i;
            p2=sum-i;
            break;
        }
    //  cerr<<i<<endl;
    }
//  cerr<<"!!!"<<p1<<" "<<p2<<endl;
    assert(p1!=-1);
    int sum1=0;
    for (int i=1;sum1<p1;i++){
    //  cerr<<sum1<<" "<<i<<endl;
        color[i-1]=1;
        sum1+=i;
    }
//  cerr<<sum1<<" "<<sum<<endl;
    if (sum1!=p1)
        color[sum1-p1-1]=0; 
}

void solve3(int sum){
    sum-=3;
    int p1=-1,p2;
    for (int i=2;i<=sum-2;i++){
        if (p[i]==i && p[sum-i]==sum-i){
            p1=i;
            p2=sum-i;
            break;
        }
    }

    assert(p1!=-1);
    p1+=3;
    int sum1=0;
    for (int i=1;sum1<p1;i++){
        color[i-1]=1;
        sum1+=i;
    }
    if (sum1!=p1)
        color[sum1-p1-1]=0; 
    if (color[2]==1)
        color[2]=2;
    else
        color[0]=color[1]=2;
    
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    cin>>n;
    int sum=n*(n+1)/2;
    if (check(sum)){
        for (int i=0;i<n;i++)
            printf("1 ");
        printf("\n");
        return 0;           
    }
    if (sum>=2 && check(sum-2)){
        for (int i=0;i<n;i++)
            printf("%d ",(i==1)+1);
        printf("\n");
        return 0;   
    }
    calc(sum);
//  for (int i=0;i<prkol;i++)
//      cerr<<primes[i]<<endl;
//  return 0;
//  cerr<<"!!"<<sum<<endl;
    if (sum%2==0)
        solve2(sum);
    else
        solve3(sum);
//  cerr<<"!!!!"<<endl;
    for (int i=0;i<n;i++)
        printf("%d ",color[i]+1);
    printf("\n");
    return 0;
}