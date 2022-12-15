#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n,vis[1000001];
int main(){
    scanf("%d",&n);
    vector<int> prime;
    for(int i=2;i<=1000000;i++)if(!vis[i]){
        prime.push_back(i);
        if(i<=1000){
            for(int j=i+i;j<=1000000;j+=i) vis[j]=1;
        }
    }

    int ans=1;
    vector<int> arr;
    for(auto &it:prime) if(n%it==0){
        int c=0;
        while(n%it==0){
            n/=it;c++;
        }
        arr.push_back(c);
        ans*=it;
    }

    printf("%d ",ans);

    int c=0,mx=0;
    for(auto &it:arr)mx=max(mx,it);

    int t=1;
    while(t<mx)t*=2;
    for(auto&it:arr)if(t!=it){
        c++;
        break;
    }
    while(t!=1){
        t/=2; c++;
    }
    printf("%d\n",c);

    return 0;
}