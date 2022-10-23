#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    while (n>0)
    {
        a.push_back(n%10);
        n=n/10;
    }
    int kq=1,t=1,tmp;
    for (int i=1;i<a.size();i++) kq=kq*9;
    for (int i=a.size()-1;i>=0;i--)
    {
        tmp=t*(a[i]-1);
        for (int j=i-1;j>=0;j--) tmp=tmp*9;
        kq=max(kq,tmp);
        t=t*a[i];
    }
    kq=max(kq,t);
    cout<<kq;
    //for (int i=0;i<a.size();i++) cout<<endl<<a[i];
    return 0;
}