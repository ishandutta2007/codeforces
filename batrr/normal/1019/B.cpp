#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

bool check(int a,int b,int a1,int b1){
    if( a<b ){
        if(a1<b1)
            return 0;
         else
            return 1;
    }else{
        if(a1<b1)
            return 1;
        else
            return 0;
    }


}
int main(){
    int n,a,b,a1,b1;

    cin>>n;
    
    cout<<"? "<<1<<endl;
    cout.flush();
    cin>>a;
    cout<<"? "<<1+n/2<<endl;
    cout.flush();
    cin>>b;
    
    if(a==b){
        cout<<"! "<<1;
        cout.flush();
        return 0;
    }
        
    if(abs(a)%2!=abs(b)%2){
        cout<<"! -1";
        cout.flush();
        return 0;
    }

    int l=1,r=1+n/2;
    while(l<=r){
        int m=(l+r)/2;

        cout<<"? "<<m<<endl;
        cout.flush();
        cin>>a1;
        cout<<"? "<<m+n/2<<endl;
        cout.flush();
        cin>>b1;
        
        if(a1==b1){
            cout<<"! "<<m;
            cout.flush();
            return 0;
        }
        
        if( !check(a,b,a1,b1) )
            l=m+1;
        else
            r=m-1;
    
    }
    assert(0);
}