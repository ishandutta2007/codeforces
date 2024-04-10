#include<iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define clr(a,v) memset(a,v,sizeof(a))
typedef long long lng;
const int INF=1000000000;
const lng LINF=1LL*INF*INF;

int n;
int A[2100];
int B[2100];

int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    cin>>n;
    forn(i,n){
        cin>>A[i];
        A[i]=abs(A[i]);
    }
    forn(i,n){
        int v=0;
        forn(j,n){
            if(j<i && A[j]<A[i])
                --v;
            if(j>i && A[j]<A[i])
                ++v;
        }
        if(v>0)
            B[i]=-A[i];
        else
            B[i]=A[i];
    }
    int res=0;
    forn(i,n){
        forn(j,i){
            if(B[j]>B[i])
                ++res;
        }
    }
    cout<<res;

    return 0;
}