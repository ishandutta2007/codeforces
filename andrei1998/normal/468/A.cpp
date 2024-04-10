#include <iostream>

using namespace std;

int main()
{
    int n=1;
    cin>>n;

    if(n==1 || n==2 || n==3){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";

    if(n==4){
        cout<<"1 * 2 = 2\n";
        cout<<"2 * 3 = 6\n";
        cout<<"6 * 4 = 24\n";

        return 0;
    }
    else if(n==5){
        cout<<"4 * 5 = 20\n";
        cout<<"3 - 1 = 2\n";
        cout<<"2 * 2 = 4\n";
        cout<<"20 + 4 = 24\n";

        return 0;
    }

    cout<<"1 + 2 = 3\n";
    cout<<"3 - 3 = 0\n";
    cout<<"5 * 0 = 0\n";

    for(int i=7;i<=n;i++)
        cout<<i<<" * 0 = 0\n";

    cout<<"4 * 6 = 24\n";
    cout<<"24 + 0 = 24\n";

    return 0;
}