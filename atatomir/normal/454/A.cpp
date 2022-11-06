#include <iostream>

using namespace std;

long n;
int a[105][105];

void Recurs(long i,long j,long dim){
    if(!dim) return;
    a[i][j] = dim;

    if(a[i-1][j] < dim-1) Recurs(i-1,j,dim-1);
    if(a[i+1][j] < dim-1) Recurs(i+1,j,dim-1);
    if(a[i][j-1] < dim-1) Recurs(i,j-1,dim-1);
    if(a[i][j+1] < dim-1) Recurs(i,j+1,dim-1);
}

int main()
{
    cin >> n;
    Recurs(n/2+1,n/2+1,n/2+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(a[i][j]) cout << 'D'; else cout << '*';
        cout << '\n';
    }
    return 0;
}