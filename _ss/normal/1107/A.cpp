#include <iostream>

using namespace std;

int main()
{
    int q,n;
    string s;
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>n>>s;
        if (n==2 && s[1]<=s[0]) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl<<2<<endl<<s[0]<<" ";
            for (int j=1;j<n;j++) cout<<s[j];
            cout<<endl;
        }
    }
    return 0;
}