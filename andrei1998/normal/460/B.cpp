#include <iostream>
#include <vector>
#include <algorithm>

#define int long long int
using namespace std;

int exp(int a,int b){
    int ans=1;
    for(int i=1;i<=b;i++)
        ans*=a;

    return ans;
}

int s(int x){
    int ans=0;

    while(x){
        ans+=(x%10);
        x/=10;
    }

    return ans;
}

vector<int> sol;

signed main()
{
    int a,b,c;
    cin>>a>>b>>c;

    for(int sx=1;sx<=81;sx++){
        int x=exp(sx,a)*b+c;

        if(x>0 && x<1000000000ll)
            if(s(x)==sx)
                sol.push_back(x);
    }

    if(!sol.size()){
        cout<<"0\n";
        return 0;
    }

    sort(sol.begin(),sol.end());

    cout<<sol.size()<<endl;
    cout<<sol[0];
    for(int i=1;i<sol.size();i++)
        cout<<' '<<sol[i];

    return 0;
}