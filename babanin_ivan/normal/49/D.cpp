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
bool a[2000];
bool b[2000];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d ",&n);
    char c;
    for (int i=0;i<n;++i){
        scanf("%c",&c);
        if (c=='1')
            a[i]=true;
        else a[i]=false;
    }
    int ans1=0;
    int ans2=0;
    for (int i=0;i<n;++i)
        b[i]=a[i];
    
    for (int i=1;i<n;++i)
        if (b[i]==b[i-1]){
            ++ans1;
            b[i]=!b[i];
        }
    for (int i=1;i<n;++i)
        if (b[i]==b[i-1])
            ans1=inf;
    ans2=ans1;


    for (int i=0;i<n;++i)
        b[i]=a[i];
    ans1=1;
    b[0]=!b[0];
    for (int i=1;i<n;++i)
        if (b[i]==b[i-1]){
            ++ans1;
            b[i]=!b[i];
        }
    for (int i=1;i<n;++i)
        if (b[i]==b[i-1])
            ans1=inf;
    ans2=min(ans2,ans1);

    ans1=0;
    for (int i=0;i<n;++i)
        b[i]=a[i];
    for (int i=n-2;i>=0;--i)
        if (b[i]==b[i+1]){
            ++ans1;
            b[i]=!b[i];
        }
    for (int i=n-2;i>=0;--i)
        if (b[i]==b[i+1])
            ans1=inf;
    ans2=min(ans2,ans1);
    
    ans1=1;
    for (int i=0;i<n;++i)
        b[i]=a[i];
    b[n-1]=!a[n-1];
    for (int i=n-2;i>=0;--i)
        if (b[i]==b[i+1]){
            ++ans1;
            b[i]=!b[i];
        }
    for (int i=n-2;i>=0;--i)
        if (b[i]==b[i+1])
            ans1=inf;
    ans2=min(ans2,ans1);
    
    
    
    
    if (ans2==inf)
        cout<<"-1"<<endl;
    else cout<<ans2;
}