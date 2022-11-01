#include <iostream>
using namespace std;
#define N 100
int main() {
    int n,m;
    char a[N][N];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
            {
                if((i+j)%2==0)
                    a[i][j]='B';
                else
                    a[i][j]='W';    
            }   
        }   
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j];
        cout<<endl;
    }

    return 0;
}