#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
    int n,k,a[500],i,j,l,t,ans,temp;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    ans=a[0];
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            vector<int> m;
            vector<int> M;
            temp=0;
            for(l=0;l<i;l++) M.push_back(a[l]);
            for(l=i;l<=j;l++) m.push_back(a[l]),temp+=a[l];
            for(l=j+1;l<n;l++) M.push_back(a[l]);
            sort(m.begin(),m.end());
            sort(M.begin(),M.end(),greater<int>());
            t=min(m.size(),M.size());
            t=min(t,k);
            for(l=0;l<t;l++){
                if(m[l]<M[l]) temp=temp-m[l]+M[l];
                else break;
            }
            if(temp>ans) ans=temp;
        }
    }
    printf("%d\n",ans);
    return 0;
}