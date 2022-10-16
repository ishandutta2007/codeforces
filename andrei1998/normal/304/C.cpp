#include <iostream>

using namespace std;

int a[100005];
int b[100005];
int c[100005];

int main()
{
    int n=0;
    cin>>n;

    if(n%2==0){
        cout<<"-1\n";
        return 0;
    }

    for(int i=1;i<=n;i++)
        a[i]=i-1;
    for(int i=1;i<=n;i++)
        b[i]=(a[i]+1)%n;
    for(int i=1;i<=n;i++)
        c[i]=(a[i]+b[i])%n;

    cout<<a[1];
    for(int i=2;i<=n;i++)
        cout<<' '<<a[i];
    cout<<endl;

    cout<<b[1];
    for(int i=2;i<=n;i++)
        cout<<' '<<b[i];
    cout<<endl;

    cout<<c[1];
    for(int i=2;i<=n;i++)
        cout<<' '<<c[i];
    cout<<endl;

    return 0;
}