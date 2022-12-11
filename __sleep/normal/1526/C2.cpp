#include<cstdio>
#include<queue>
std::priority_queue<int> pq;
long long sum; 
int t,n,a,ans;
int main(){
    scanf("%d",&n);
    ans=n;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
        pq.push(-a);
        if(sum<0){
            sum+=pq.top();
            pq.pop();
            ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}