#include <bits/stdc++.h>
#define pii pair<int,int>
#define ac cout<<ans<<endl
#define rep(i,n) for(int (i)=0;(i)<(n);i++)
#define rep1(i,n) for(int (i)=1;(i)<=(n);i++)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
 
using namespace std;
int a[]={4, 8, 15, 16, 23, 42};
int db[10];
void solve()
{
        for(int i=1;i<=4;i++)
       {
        printf("? %d %d\n",i,i+1);
        fflush(stdout);
        scanf("%d",&db[i]);
       }
       while(1){
         if(a[0]*a[1]==db[1]&&a[1]*a[2]==db[2]&&a[2]*a[3]==db[3]&&a[3]*a[4]==db[4])break; 
       else next_permutation(a,a+6);
       }
 
       cout<<"! ";
       for(int i=0;i<6;i++)
       {
           cout<<a[i]<<' ';
       }
}
 
int main()
{
    IOS;
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}