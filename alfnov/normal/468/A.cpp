#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<4)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(n&1)
    {
		cout<<"5 - 1 = 4"<<endl;
		cout<<"4 - 2 = 2"<<endl;
		cout<<"2 * 3 = 6"<<endl;
		cout<<"6 * 4 = 24"<<endl;
        for(int i=6;i<=n;i+=2)
        {
            cout<<(i+1)<<" - "<<i<<" = 1"<<endl;
            cout<<"24 * 1 = 24"<<endl;
        }
    }else
    {
    	cout<<"1 * 2 = 2"<<endl;
    	cout<<"2 * 3 = 6"<<endl;
    	cout<<"6 * 4 = 24"<<endl;
    	for(int i=5;i<=n;i+=2)
        {
            cout<<(i+1)<<" - "<<i<<" = 1"<<endl;
            cout<<"24 * 1 = 24"<<endl;
        }
	}
    return 0;
}