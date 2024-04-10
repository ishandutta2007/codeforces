#include <iostream>

using namespace std;

#define maxN 1011

long n,m,i,x,y,k;
bool a[maxN][maxN];

bool check(long x,long y){
    return a[x][y]&&a[x+1][y]&&a[x][y+1]&&a[x+1][y+1];
}

int main()
{
    cin >> n >> m >> k;
    for(i=1;i<=k;i++){
        cin >> x >> y;
        a[x][y] = true;
        if(check(x-1,y-1)||check(x-1,y)||check(x,y-1)||check(x,y)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}