#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,x,i,k;
    vector<int> v1,v2,v3;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x==1) v1.push_back(i);
        else if(x==2) v2.push_back(i);
        else v3.push_back(i);
    }
    printf("%d\n",k=min(v1.size(),min(v2.size(),v3.size())));
    for(i=0;i<k;i++){
        printf("%d %d %d\n",v1[i],v2[i],v3[i]);
    }
    return 0;
}