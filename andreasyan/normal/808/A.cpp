#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=1000000000;i*=10)
    {
        for(int j=1;j<=9;++j)
        {
            if(n<(i*j))
            {
                cout<<(i*j)-n<<endl;
                return 0;
            }
        }
    }
    return 0;
}