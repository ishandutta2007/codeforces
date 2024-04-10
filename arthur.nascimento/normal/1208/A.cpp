#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        n %= 3;
        if(n == 0) printf("%d\n",a);
        if(n == 1) printf("%d\n",b);
        if(n == 2) printf("%d\n",a^b);
    }
    
}