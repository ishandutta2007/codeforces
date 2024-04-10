#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct seg{
    int q;
    int n;
    int l;
    int r;
    int x;
    bool operator<(const seg& k) const{
        return x<k.x;
    }
};
inline bool intersect(const seg& x,const seg& y){
    return max(x.l,y.l)<=min(x.r,y.r);
}
int lc[200000],rc[200000];
int main(){
    int i,j,t,n,m,pre,count;
    seg temp;
    scanf("%d%d",&n,&m);
    vector<seg> query,ans; 
    for(i=1,j=1,t=1;i<200000;i++,j++){
        if(i==t){
            lc[i]=j++;
            rc[i]=j;
            t<<=1;
        }
        else lc[i]=rc[i]=j;
    }
    temp.q=0;
    while(m--){
        temp.q++;
        scanf("%d",&t);
        if(t==2){
            scanf("%d%d",&temp.n,&j);
            temp.l=temp.r=j;
            for(i=temp.n;i<n;i++){
                temp.l=lc[temp.l];
                temp.r=rc[temp.r];
            }
            query.push_back(temp);
        }
        else{
            scanf("%d%d%d%d",&temp.n,&temp.l,&temp.r,&temp.x);
            for(i=temp.n;i<n;i++){
                temp.l=lc[temp.l];
                temp.r=rc[temp.r];
            }
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    for(i=0;i<query.size();i++){
        pre=0;
        count=0;
        for(j=0;j<ans.size();j++){
            if(ans[j].q<query[i].q && ans[j].x!=pre && 
               ans[j].n>=query[i].n && intersect(query[i],ans[j])){
                count++;
                pre=ans[j].x;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}