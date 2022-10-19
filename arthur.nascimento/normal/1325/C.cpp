#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

int dg[maxn];
int a[maxn];
int b[maxn];
int ans[maxn];

int main(){
    
    int n;
    scanf("%d",&n);
    vector<int> v;
    
    for(int i=0;i<n-1;i++){
        scanf("%d%d",a+i,b+i);
        dg[a[i]]++;
        dg[b[i]]++;
        v.pb(i);
    }
    
    sort(v.begin(), v.end(), [](int i,int j){
       return min(dg[a[i]],dg[b[i]]) <  min(dg[a[j]],dg[b[j]]);
    });
    
    for(int i=0;i<n-1;i++)
        ans[v[i]] = i;
        
    for(int i=0;i<n-1;i++)
        printf("%d\n",ans[i]);
    
}