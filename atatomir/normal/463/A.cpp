#include <iostream>

using namespace std;

long n,s,i,x,y,maxim=-1;

int main()
{
    cin >> n >> s;
    for(i=1;i<=n;i++){
        cin >> x >> y;
        if((x == s) && (y == 0)){maxim = max(maxim,0L); continue;}
        if(x >= s) continue;
        if(y == 0) y = 100;
        maxim = max(maxim,100-y);
    }
    cout << maxim;
    return 0;
}