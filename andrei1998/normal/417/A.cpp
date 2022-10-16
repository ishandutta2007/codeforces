#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int c,d,n,m,k;
    cin>>c>>d>>n>>m>>k;

    int ramasi=max(0,n*m-k);
    int cost=(ramasi/n)*min(n*d,c);
    cost+=min((ramasi%n)*d,c);

    cout<<cost<<'\n';
    return 0;
}