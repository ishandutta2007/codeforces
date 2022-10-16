#include <iostream>

using namespace std;

int main()
{
    int n;
    long long int x;
    int y;

    cin>>n>>x>>y;

    if(n>y){
        cout<<"-1\n";
        return 0;
    }

    if(n-1+(y-n+1ll)*(y-n+1ll)<x){
        cout<<"-1\n";
        return 0;
    }
    else{
        cout<<(y-n+1);
        for(int i=1;i<n;i++)
            cout<<" 1";
        cout<<'\n';
    }

    return 0;
}