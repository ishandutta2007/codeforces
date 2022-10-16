#include<bits/stdc++.h>
using namespace std;
//123456789
string a[20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string b[10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int c;
int main()
{
    cin>>c;
    if(c<=19)cout<<a[c];
    else if(c%10==0)cout<<b[c/10];
    else cout<<b[c/10]<<"-"<<a[c%10];
    return 0;
}