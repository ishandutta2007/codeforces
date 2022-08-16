#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const int N = 1e5 + 3;
ll mod = 1e9 + 7;

ll n,k,u,v,m,k1,st,a[N],i,j;
ll ch[N];

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    i = 0;
    while(i < n-1){
        j = i;
        while(i < n-1 and a[i] <= a[i+1])
            i += 1;
        st = i;
        while(i < n-1 and a[i] >= a[i+1])
            i += 1;
        ll st1 = i;
        for(k = j; k <= i; k++){
            st1 = k;
            if(k > st && a[k] == a[i]) break;
            ch[k] = i;
        }
        i = st1;
    }
    ch[n-1] = n-1;

    while(m--){
        cin>>u>>v;
        u -= 1;
        v -= 1;
        if(u == v)
            printf("Yes\n");
        else if(ch[u] == ch[v])
            printf("Yes\n");
        else if(v <= ch[u])
            printf("Yes\n");
        else
            printf("No\n");
    }
}