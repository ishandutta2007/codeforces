

#include <bits/stdc++.h>
using namespace std;
#define ll long long


ifstream fin("input.txt");
ofstream fout("output.txt");

ll q,ans,p=1;

int main()
{ 
    cin>>q;
    while(q)
    {
        
        ll ex=q%10;
        if(ex==4)
            ans+=p;
        else
            ans+=p*2;
        q/=10;
        p<<=1;      
    }
    cout<<ans;
    return 0;
}