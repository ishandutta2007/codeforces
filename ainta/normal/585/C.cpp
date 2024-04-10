#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long>V;
bool Do(long long x, long long y){
    if(x==y){
        if(x==1)return true;
        return false;
    }
    if(x>y){
        long long t = x/y;
        if(x%y==0)t--;
        V.push_back(t*2);
        return Do(x-y*t,y);
    }
    else{
        long long t = y/x;
        if(y%x==0)t--;
        V.push_back(t*2+1);
        return Do(x,y-x*t);
    }
}
int main(){
    long long x, y;
    scanf("%lld%lld",&x,&y);
    if(!Do(x,y)){
        puts("Impossible");
        return 0;
    }
    for(auto &t : V){
        if(t%2==0){
            printf("%lldA",t/2);
        }
        else{
            printf("%lldB",t/2);
        }
    }
    puts("");
}