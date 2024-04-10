#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a>>b;
    long double a_on_bottom=b*log(a);
    long double b_on_bottom=a*log(b);
    if(a==b){
        cout << "=";
        return 0;
    }
    if(abs(a_on_bottom-b_on_bottom)<0.0000001){
        cout << "=";
        return 0;
    }
    if(a_on_bottom>b_on_bottom)
        cout << ">";
    else if(b_on_bottom>a_on_bottom)
        cout << "<";
    return 0;
}