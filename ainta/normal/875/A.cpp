#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int Sum(int a){
    if(!a)return 0;
    return Sum(a/10)+a%10;
}
int main(){
    int i;
    scanf("%d",&n);
    vector<int>R;
    for(i=max(0,n-1000);i<=n;i++){
        if(Sum(i)+i==n){
            R.push_back(i);
        }
    }
    printf("%d\n",R.size());
    for(i=0;i<R.size();i++)printf("%d ",R[i]);
}