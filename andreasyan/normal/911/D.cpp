#include <iostream>
using namespace std;
const int N=2000;

int n;
int a[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int ans=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<i;++j)
            if(a[i]<a[j])
                ans^=1;
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        if(((r-l+1)/2)%2==1)
            ans^=1;
        if(ans==0)
            cout<<"even"<<endl;
        else
            cout<<"odd"<<endl;
    }
    return 0;
}