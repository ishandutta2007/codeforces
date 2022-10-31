#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)110)

ll t,n;

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--)
    {
        ll min1,max1;
        cin>>n;
        if(n%2==1)min1=1,max1=1;
        else
        {
            cout<<"? 1 2"<<"\n";fflush(stdout);
            char c;
            cin>>c;
            if(c=='<' || c=='=')min1=1,max1=2;
            else min1=2,max1=1;
        }
        for(int i=(n%2==0)+2;i<=n-1;i+=2)
        {
            ll min2,max2;
            char c;

            cout<<"? "<<i<<" "<<i+1<<"\n";fflush(stdout);
            cin>>c;
            if(c=='<' || c=='=')min2=i,max2=i+1;
            else min2=i+1,max2=i;

            cout<<"? "<<min1<<" "<<min2<<"\n";fflush(stdout);
            cin>>c;
            if(c=='>')min1=min2;

            cout<<"? "<<max1<<" "<<max2<<"\n";fflush(stdout);
            cin>>c;
            if(c=='<' || c=='=')max1=max2;
        }
        cout<<"! "<<min1<<" "<<max1<<"\n";fflush(stdout);
    }
}