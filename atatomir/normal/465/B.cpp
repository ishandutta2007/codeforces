#include <iostream>

using namespace std;

long n,i,x;
long cont,rez;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        if(x){
            cont++;
        } else {
            rez += (cont>0?cont+1:0);
            cont = 0;
        }
    }
    rez += (cont>0?cont+1:0);
    if(rez)rez--;
    cout << rez;
    return 0;
}