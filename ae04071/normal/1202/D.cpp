#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n;
        scanf("%d",&n);
        
        int x=n%31125, y=248, z=n/31125;
        printf("133");
        for(int i=0;i<x;i++) printf("7");
        for(int i=0;i<y;i++) printf("3");
        for(int i=0;i<z;i++) printf("7");
        puts("");
    }
    return 0;
}