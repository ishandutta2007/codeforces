#include <iostream>

using namespace std;

int a[100005];

int main()
{
    int n=0,r=0;
    cin>>n>>r;

    for(int i=1;i<=n-1;i++)
        cin>>a[i];

    int unde=1;
    while(1) {
        if(unde==n)
            break;
        if(unde==r)
            break;

        unde=unde+a[unde];
    }

    if(unde==r)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}