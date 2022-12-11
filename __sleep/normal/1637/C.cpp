#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=300005;
int n,t,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> p;
        long long m=0,s=0,c=n-2;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(i==1||i==n) continue;
            if(a[i]&1) ++m,p.push_back(i);
            s+=(a[i]+1)/2;
            if(a[i]==1) --c;
        }
        if((n==3&&m==1)||!c){puts("-1"); continue;}
        printf("%lld\n",s);
    }
    return 0;
}