#include <iostream>
#include <string>

#define M 10

using namespace std;

int n,a[M],s=0,b[M],k=0;
bool f=0;

int myabs(int x){
    return x<0 ? -x:x;
}

void read(void){
    cin>>n;
    for (int i=0,x; i<n; ++i){
        cin>>x;
        a[x]++;
        s+=x;
    }

    for (int x1=0; 3*x1<=s; ++x1)
        if ((s-3*x1)%4==0){
            int x=x1;
            int y=(s-3*x)/4;
            int z=n-x-y;

            for (int i=0; i<=4; ++i)
                b[i]=a[i];
            int ans=0;

            for (int j=4; j>=0; --j){
                int to=min(b[j],y);
                y-=to;
                b[j]-=to;
                ans+=(myabs(4-j)*to);
            }

            for (int j=4; j>=0; --j){
                int to=min(b[j],x);
                x-=to;
                b[j]-=to;
                ans+=(myabs(3-j)*to);
            }

            for (int j=4; j>=0; --j)
                ans+=(j*b[j]);


            if (f)
                k=min(k,ans);
            else
                f=1,k=ans;
        }
        
    if (f)
        cout<<k/2<<"\n";
    else
        cout<<"-1\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read();
    return 0;
}