#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1e6+123,inf=1e9,mod=1e9+7;
int n,k,ans,a[maxn],l[maxn],r[maxn];
ll get(int x){                                                      
    int y=x/k;  
    //cerr<<x<<" "<<y<<endl;
    return ( 1ll*y*x - 1ll*k*( (1ll*y*(y+1)/2)%mod ) )%mod;
}
ll get(int l,int r){
    if(l>r)
        return 0;
    return get(r-l+1);
}
int main(){   
    scanf("%d%d",&n,&k);
    k--;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    stack< int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i] )
            st.pop();
        if( st.empty() )
            l[i]=0;
        else
            l[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]<=a[i] )
            st.pop();
        if( st.empty() )
            r[i]=n-1;
        else
            r[i]=st.top()-1;
        st.push(i);
    }
    for(int i=0;i<n;i++){
        ll cnt= ( get(l[i],r[i])-get(l[i],i-1)-get(i+1,r[i]) )%mod;
        if(cnt<0)   
            cnt+=mod;
        ans=(ans + 1ll*cnt*a[i]%mod )%mod;
    }
    printf("%d",ans);


    return 0;
}