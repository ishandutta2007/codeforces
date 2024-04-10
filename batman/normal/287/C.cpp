#include<bits/stdc++.h>
#define ll long long
#define N ((ll)101*1000)
using namespace std;
ll n,a[N],p[N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==2 || n%4==3 || n%4==2)return cout<<-1,0;

        for(int i=1,l=1,r=n;i<=n-(n%2);l+=2,r-=2,i+=4)
            p[l]=l+1,p[l+1]=r,p[r]=r-1,p[r-1]=l;

        if(n%2==1)p[(n+1)/2]=(n+1)/2;
        for(int i=1;i<=n;i++)cout<<p[i]<<" ";
        return 0;

}