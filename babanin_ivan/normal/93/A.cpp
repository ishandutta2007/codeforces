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
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int maxans=inf;
int n,m,l,r;

void print(int x){
    cout<<min(maxans,x)<<endl;
    exit(0);
}



int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m>>l>>r;
    --l;
    --r;
    --n;
    
    if ((l % m==0) && ( (r % m)==m-1) )
        print(1);

    if ((l/m) == (r/m))
        print(1);
    
    if ((r/m)==((l/m)+1) )
        maxans=2;
    if (r==n)
        maxans=2;

    if ((l % m) ==0){
        if (r ==n)
            print(1);
        else print(2);
    }

    if ( (r % m)==m-1)
        print(2);

    if ( (r%m) ==((l % m)-1))
        print(2);
    print(3);
    return 0;
}