#include <iostream>
#include <vector>
using namespace std;
vector<int> o;

int main()
{
    int n,a[1001],x,y=0;
    bool kt;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x-y;
        y=x;
    }
    for (int i=1;i<=n;i++)
    {
        kt=true;
        for (int j=i+1;j<=n;j++)
            if (a[(j-1)%i+1]!=a[j])
            {
                kt=false;
                break;
            }
        if (kt) o.push_back(i);
    }
    cout<<o.size()<<endl;
    cout<<o[0];
    for (int i=1;i<o.size();i++) cout<<" "<<o[i];
    return 0;
}