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

int a[5];
void print(int p){
    if (p==0)
        printf("S\n");
    if (p==1)
        printf("M\n");
    if (p==2)
        printf("L\n");
    if (p==3)
        printf("XL\n");
    if (p==4)
        printf("XXL\n");
}

int l,r;
void solve(int k){
    l=k;
    r=k;
    while (true){
        if (r<5 && a[r]){
            print(r);
            --a[r];
            return;
        }
        if (l>=0 && a[l]){
            print(l);
            --a[l];
            return;
        }
        --l;
        ++r;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    int k;
    scanf("%d ",&k);
    string s;
    for (int i=0;i<k;++i){
        getline(cin,s,'\n');
        if (s=="S")
            solve(0);
        if (s=="M")
            solve(1);
        if (s=="L")
            solve(2);
        if (s=="XL")
            solve(3);
        if (s=="XXL")
            solve(4);
    }
}