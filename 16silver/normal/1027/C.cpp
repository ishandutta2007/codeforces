#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x, y;
int main(){
    int T,t,n,i,tmp,l,mxx,mxy;
    scanf("%d",&T);
    for(t=0;t<T;t++){
        scanf("%d",&n);
        x.clear();
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            x.push_back(tmp);
        }
        sort(x.begin(),x.end());
        y.clear();
        int comb=1;
        for(i=1;i<n;i++){
            if(x[i]==x[i-1]){
                comb++;
            }
            else{
                if(comb>1) y.push_back(x[i-1]);
                if(comb>3) y.push_back(x[i-1]);
                comb=1;
            }
        }
        if(comb>1) y.push_back(x[n-1]);
        if(comb>3) y.push_back(x[n-1]);
        l=y.size();
        mxx=0;
        mxy=1;
        for(i=1;i<l;i++){
            if(mxx*y[i]<mxy*y[i-1]){
                mxx=y[i-1];
                mxy=y[i];
            }
        }
        printf("%d %d %d %d\n",mxx,mxx,mxy,mxy);
    }
}