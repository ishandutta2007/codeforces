#include <iostream>

using namespace std;

long n,i,cont;
char c;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> c;
        if(c == '0') break;
        cont++;
    }
    cont++;
    cout << min(cont,n);
    return 0;
}