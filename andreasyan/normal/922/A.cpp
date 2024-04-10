#include <iostream>
#include <algorithm>
using namespace std;

int x,y;
int main()
{
    cin>>x>>y;
	if(y==0)
	{
		cout<<"No"<<endl;
		return 0;
	}
	if(y==1 && x!=0)
	{
	    cout<<"No"<<endl;
	    return 0;
	}
    if((y-1)<=x && (x-(y-1))%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
//	system("pause");
    return 0;
}