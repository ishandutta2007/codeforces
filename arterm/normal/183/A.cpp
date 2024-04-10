#include <iostream>
#include <string>

#define long long long

using namespace std;

long a=1,b=1,n;
string s;

void read(void){
    cin>>n;
    while (n--){
        cin>>s;
        if (s=="UL" || s=="DR")
        a++;
        if (s=="UR" || s=="DL")
        b++;
        if (s=="ULDR")
        a++,b++;
    }
    cout<<a*b<<"\n";
}

int main()
{
    read();
    return 0;
}