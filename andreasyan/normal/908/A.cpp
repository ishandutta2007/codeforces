#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
using namespace std;
const int N=55;

char a[N];
int main()
{
    cin>>a;
    int n=strlen(a);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='a' || a[i]== 'e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
        {
            ++ans;
            continue;
        }
        int x=a[i]-'0';
        if(a[i]>='0' && a[i]<='9' && x%2==1)
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}