#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int x[200000];
int fst[200001],lst[200001];
int prv,curr,aaa;
int ans;
int check[200001];
vector<int> chl;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<200001;i++) fst[i]=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
        if(fst[x[i]]==-1) fst[x[i]]=i;
        lst[x[i]]=i;
    }
    curr=0;
    while(curr<n){
        prv = curr;
        chl.clear();
        aaa=lst[x[curr]];
        check[x[curr]]++;
        if(check[x[curr]]==1) chl.push_back(x[curr]);
        while(curr<aaa){
            curr++;
            aaa=max(aaa,lst[x[curr]]);
            check[x[curr]]++;
            if(check[x[curr]]==1) chl.push_back(x[curr]);
        }
        int tmp=0;
        for(int i=0;i<chl.size();i++){
            tmp=max(tmp,check[chl[i]]);
        }
        ans += (aaa-prv+1) - tmp;
        curr++;
    }
    printf("%d\n",ans);
}